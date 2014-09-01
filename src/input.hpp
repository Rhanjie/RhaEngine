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
}

#endif // INPUT_HPP_INCLUDED
