#include "managerLibs.hpp"

#include "extension.hpp"
#include "primitives.hpp"
#include "window.hpp"
#include "shader.hpp"
#include "logger.hpp"
#include "input.hpp"

int main(int argc, char * argv[]){
    rha::cLogger logger("logger.rhAf");
    rha::cWindow window(glm::vec2(800, 600), "RhaEngine - demo", logger);
    rha::cKeyboard keyboard(window.getHandle());
    rha::cShader shader(&logger);

    logger<<"\n"<<reinterpret_cast<const char*>(glGetString(GL_VENDOR))<<"\n"
      <<reinterpret_cast<const char*>(glGetString(GL_RENDERER))<<"\n"
      <<"OpenGL version: "<<reinterpret_cast<const char*>(glGetString(GL_VERSION))<<"\n\n";

    shader.loadFromFile("vertexShader.rhAf", "fragmentShader.rhAf");
    shader.createProgram();

    rha::cPrimitive primitive(rha::cPrimitive::triangle);
    primitive.addVertex(glm::vec3(-0.5f, -0.5f, 0.0f));
    primitive.addVertex(glm::vec3(0.5f, -0.5f, 0.0f));
    primitive.addVertex(glm::vec3(0.0f,  0.5f, 0.0f));
    primitive.build();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while(window.getRun()){
        if(keyboard.press(GLFW_KEY_ESCAPE)||logger.getExit())
            window.close();
        /**glfwWindowShouldClose(window.getHandle()**/// - class event.

        window.clear(125.0f, 125.0f, 255.0f);

        shader.use();
        primitive.draw();
        //...

        window.display();
        glfwPollEvents(); //- class event.
    }
    return 0;
}
