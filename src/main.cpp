#include "managerLibs.hpp"

#include "window.hpp"
#include "logger.hpp"
#include "input.hpp"

int main(int argc, char * argv[]){
    rha::cLogger logger("logger.rhAf");
    rha::cWindow window(glm::vec2(600, 400), "RhaEngine - demo", logger);
    rha::cKeyboard keyboard(window.getHandle());

    logger<<reinterpret_cast<const char*>(glGetString(GL_VENDOR))
      <<reinterpret_cast<const char*>(glGetString(GL_RENDERER))
      <<reinterpret_cast<const char*>(glGetString(GL_VERSION));
    while(window.getRun()){
        if(keyboard.press(GLFW_KEY_ESCAPE)||logger.getExit())
            window.close();
        /**glfwWindowShouldClose(window.getHandle()**/// - class event.
        //draw&physics

        window.display();
        glfwPollEvents(); //- class event.
    }
    return 0;
}
