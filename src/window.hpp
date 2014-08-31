#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "managerLibs.hpp"
#include "logger.hpp"

namespace rha{
    class cWindow{
        private:
         bool run;
        public:
         cWindow(glm::vec2 size, const std::string& title, cLogger& logger);

         GLFWwindow* handle;


         inline bool getRun(){return run;}
         inline void close(){glfwTerminate(); run=false;}
         inline void display(){glfwSwapBuffers(handle);}
    };
}

#endif // WINDOW_HPP_INCLUDED
