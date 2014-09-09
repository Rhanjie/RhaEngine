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

         void clear(GLclampf r=0, GLclampf g=0, GLclampf b=0);
         void close(){glfwTerminate(); run=false;}
         void display(){glfwSwapBuffers(handle);}

         inline GLFWwindow* getHandle(){return handle;}
         inline bool getRun(){return run;}
    };
}

#endif // WINDOW_HPP_INCLUDED
