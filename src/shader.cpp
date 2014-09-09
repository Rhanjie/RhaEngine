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

    auxiliary=codeVertex.c_str();
    glShaderSource(vertexShaderID, 1, &auxiliary, NULL);
    glCompileShader(vertexShaderID);

    auxiliary=codeFragment.c_str();
    glShaderSource(fragmentShaderID, 1, &auxiliary, NULL);
    glCompileShader(fragmentShaderID);
    *logger<<"Shaders were compiled!\n";
}

void cShader::createProgram(){ //todo - logger
    programID=glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}
void cShader::use(){
    glUseProgram(programID);
}
