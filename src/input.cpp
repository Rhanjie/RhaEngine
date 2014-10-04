#include "input.hpp"

using namespace rha;
cKeyboard::cKeyboard(GLFWwindow* handle){
    this->handle=handle;
    glfwSetInputMode(this->handle, GLFW_STICKY_KEYS, GL_TRUE);
} bool cKeyboard::press(short int key){
    if(glfwGetKey(this->handle, key)==GLFW_PRESS)
        return true;
    else return false;
} cMouse::cMouse(GLFWwindow* handle){
    this->handle=handle;
    glfwSetInputMode(handle,
        GLFW_STICKY_MOUSE_BUTTONS, GL_TRUE);
} void cMouse::setPosition(glm::dvec2 position){
    this->position=position;

    glfwSetCursorPos(handle, this->position.x, this->position.y);
}
