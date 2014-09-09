#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED
#include "managerLibs.hpp"
#include "logger.hpp"

namespace rha{
    class cShader{
        private:
         cLogger* logger;

         GLuint programID;
         GLuint vertexShaderID;
         GLuint fragmentShaderID;
        public:
         cShader(cLogger* logger);
         ~cShader();

         void use();
         void createProgram();
         void loadFromFile(std::string pathVertex, std::string pathFragment);
         void loadFromMemory(std::string codeVertex, std::string codeFragment);
    };
}

#endif // SHADER_HPP_INCLUDED
