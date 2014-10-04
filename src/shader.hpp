#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED
#include "managerLibs.hpp"
#include "logger.hpp"

namespace rha{
    enum typeUniform{tVec4, tVec3, tVec2, tMat4, tFloat, tInt, tBool};
    class cShader{
        private:
         cLogger* logger;

         //GLuint programID;
         GLuint vertexShaderID;
         GLuint fragmentShaderID;

         void sendUniform(void* data, typeUniform type, GLuint location);
        public:
         cShader(cLogger* logger);
         ~cShader();

         void bind(bool use=true);
         void createProgram();
         void loadFromFile(std::string pathVertex, std::string pathFragment);
         void loadFromMemory(std::string codeVertex, std::string codeFragment);
         void getUniformLocation(void* data, typeUniform type, std::string name);
         GLuint programID;
    };
}

#endif // SHADER_HPP_INCLUDED
