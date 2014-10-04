#include "shader.hpp"

using namespace rha;
cShader::cShader(cLogger* logger){
    this->logger=logger;

    vertexShaderID=glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderID=glCreateShader(GL_FRAGMENT_SHADER);
} cShader::~cShader(){
    if(vertexShaderID!=NULL) glDeleteProgram(vertexShaderID);
    if(fragmentShaderID!=NULL) glDeleteProgram(fragmentShaderID);
    if(programID!=NULL) glDeleteProgram(programID);
}

void cShader::loadFromFile(std::string pathVertex, std::string pathFragment){
    std::fstream file;
    std::string line="",
     codeVertex="", codeFragment="";

    file.open(pathVertex.c_str());
    if(!file.good()){*logger<<"ERROR: File \""<<pathVertex<<"\" hasn't not been opened!\n"; return;}
    while(std::getline(file, line)){
        codeVertex+="\n"+line;
    } file.close();
    file.open(pathFragment.c_str());
    if(!file.good()){*logger<<"ERROR: File \""<<pathFragment<<"\" hasn't not been opened!\n"; return;}
    while(std::getline(file, line)){
        codeFragment+="\n"+line;
    } file.close();
    *logger<<"Loading files of shader code successfully completed\n";
    this->loadFromMemory(codeVertex, codeFragment);
}
void cShader::loadFromMemory(std::string codeVertex, std::string codeFragment){ //todo - logger
    char const* auxiliary;
    GLint result=GL_FALSE,
      logLength=0;

    auxiliary=codeVertex.c_str();
    glShaderSource(vertexShaderID, 1, &auxiliary, NULL);
    glCompileShader(vertexShaderID);
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    if(result==GL_FALSE){
        glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char>shaderErrorMessage(logLength);
        glGetShaderInfoLog(vertexShaderID, logLength, NULL, &shaderErrorMessage[0]);
        *logger<<"ERROR: VertexShader wasn't compiled!\n"<<&shaderErrorMessage[0];
        return;
    }

    auxiliary=codeFragment.c_str();
    glShaderSource(fragmentShaderID, 1, &auxiliary, NULL);
    glCompileShader(fragmentShaderID);
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
    if(result==GL_FALSE){
        glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char>shaderErrorMessage(logLength);
        glGetShaderInfoLog(fragmentShaderID, logLength, NULL, &shaderErrorMessage[0]);
        *logger<<"ERROR: FragmentShader wasn't compiled!\n"<<&shaderErrorMessage[0];
        return;
    } *logger<<"Shaders were compiled!\n";
}

void cShader::createProgram(){
    GLint result=GL_FALSE,
      logLength=0;

    programID=glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    if(result==GL_FALSE){
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char>programErrorMessage(logLength);
        glGetProgramInfoLog(programID, logLength, NULL, &programErrorMessage[0]);
        *logger<<"ERROR: ShaderProgram wasn't create!\n"<<&programErrorMessage[0];
        return;
    }

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}
void cShader::bind(bool use){
    if(use) glUseProgram(programID);
    else glUseProgram(NULL);
}

void cShader::sendUniform(void* data, typeUniform type, GLuint location){
    switch(type){
        case tVec4: {glUniform4fv(location, 1, glm::value_ptr(*static_cast<glm::vec4*>(data))); break;}
        case tVec3: {glUniform3fv(location, 1, glm::value_ptr(*static_cast<glm::vec3*>(data))); break;}
        case tVec2: {glUniform2fv(location, 1, glm::value_ptr(*static_cast<glm::vec2*>(data))); break;}
        case tMat4: {glUniformMatrix4fv(location, 1, GL_TRUE, glm::value_ptr(*static_cast<glm::mat4*>(data))); break;}
        case tFloat: {glUniform1f(location, *static_cast<GLfloat*>(data)); break;}
        case tInt: {glUniform1i(location, *static_cast<GLint*>(data)); break;}
        //case tBool: {glUniform(location, 1, ); break;}
    }
}
void cShader::getUniformLocation(void* data, typeUniform type, std::string name){
    GLuint location;
    this->bind();
    location=glGetUniformLocation(this->programID, name.c_str());
    this->sendUniform(data, type, location);
    this->bind(0);
}
