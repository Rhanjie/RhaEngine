#ifndef INPUT_HPP_INCLUDED
#define INPUT_HPP_INCLUDED
#include "managerLibs.hpp"

namespace rha{
    class cKeyboard{
        private:
         GLFWwindow* handle;
        public:
         cKeyboard(GLFWwindow* handle);
         bool press(short int key);
    };
    class cMouse{
        private:
         GLFWwindow* handle;
         glm::dvec2 position;
        public:
         cMouse(GLFWwindow* handle);

         void setPosition(glm::dvec2 position);
         inline glm::dvec2 getPosition(){glfwGetCursorPos(handle, &position.x, &position.y); return position;}
    };
}

#endif // INPUT_HPP_INCLUDED
