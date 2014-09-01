#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "managerLibs.hpp"
#include "logger.hpp"

namespace rha{
    class cWindow{
        private:
         GLFWwindow* handle;
         bool run;
        public:
         cWindow(glm::vec2 size, const std::string& title, cLogger& logger);

         inline void close(){glfwTerminate(); run=false;}
         inline void display(){glfwSwapBuffers(handle);}
         inline bool getRun(){return run;}
         inline GLFWwindow* getHandle(){return handle;}
    };
}

#endif // WINDOW_HPP_INCLUDED
