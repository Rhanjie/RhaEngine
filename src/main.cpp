#include "managerLibs.hpp"

#include "window.hpp"
#include "logger.hpp"
#include "input.hpp"

int main(int argc, char * argv[]){
    rha::cLogger logger("logger.rhAf");
    rha::cWindow window(glm::vec2(600, 400), "RhaEngine - demo", logger);

    logger<<reinterpret_cast<const char*>(glGetString(GL_VENDOR)); logger<<"\n";
    glfwSetInputMode(window.handle, GLFW_STICKY_KEYS, GL_TRUE);
    while(window.getRun()){
        if(glfwGetKey(window.handle, GLFW_KEY_ESCAPE)==GLFW_PRESS
           ||glfwWindowShouldClose(window.handle)||logger.getExit()) window.close();

        //draw&physics

        window.display();
        glfwPollEvents();
    }
    return 0;
}
