#include "managerLibs.hpp"

#include "extension.hpp"
#include "primitives.hpp"
#include "window.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include "logger.hpp"
#include "input.hpp"

int main(int argc, char * argv[]){
    rha::cLogger logger("logger.rhAf");
    rha::cWindow window(glm::vec2(800, 600), "RhaEngine - demo", logger);
    rha::cCamera camera(glm::vec3(-1.0f, -1.0f, -6.0f), 45.0f);
    rha::cKeyboard keyboard(window.getHandle());
    rha::cMouse mouse(window.getHandle());
    rha::cShader shader(&logger);

    logger<<"\n"<<reinterpret_cast<const char*>(glGetString(GL_VENDOR))<<"\n"
      <<reinterpret_cast<const char*>(glGetString(GL_RENDERER))<<"\n"
      <<"OpenGL version: "<<reinterpret_cast<const char*>(glGetString(GL_VERSION))<<"\n\n";

    shader.loadFromFile("vertexShader.rhAf", "fragmentShader.rhAf");
    shader.createProgram();

    rha::cPrimitive primitive(rha::cPrimitive::triangle);
    primitive.addVertex(glm::vec3(0.0f, -0.5f, 0.0f), glm::vec4(255, 0, 0, 255));
    primitive.addVertex(glm::vec3(-0.5f, 1.0f, 0.0f), glm::vec4(0, 255, 0, 255));
    primitive.addVertex(glm::vec3(0.5f,  1.0f, 0.0f), glm::vec4(0, 0, 255, 255));
    primitive.build();

    int angle=0;
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while(window.getRun()){
        mouse.getPosition();
        camera.update(&window, &mouse, &keyboard);
        /**glfwWindowShouldClose(window.getHandle()**///TODO -> class event.
        mouse.setPosition(glm::vec2(window.getSize().x/2, window.getSize().y/2));

        glfwPollEvents(); //TODO -> class event.
        if(keyboard.press(GLFW_KEY_W))camera.move(0.2f);
        if(keyboard.press(GLFW_KEY_S))camera.move(-0.2f);
        if(keyboard.press(GLFW_KEY_D))camera.rotate(0.1f);
        if(keyboard.press(GLFW_KEY_A))camera.rotate(-0.1f);
        if(keyboard.press(GLFW_KEY_ESCAPE)||logger.getExit())
            window.close();

        if(angle>=360) angle=0;
        primitive.move(glm::vec3(0.0f, 0.0f, -5.0f));
        primitive.rotate(angle);
        angle+=2;

        shader.getUniformLocation(&camera.getView(), rha::tMat4, "view");
        shader.getUniformLocation(&camera.getProjection(), rha::tMat4, "projection");
        window.clear(125, 125, 255);

        //...
        shader.getUniformLocation(&primitive.getModel(), rha::tMat4, "model");
        shader.bind();
         primitive.draw();
        shader.bind(0);
        //...

        window.display();
    }
    return 0;
}
