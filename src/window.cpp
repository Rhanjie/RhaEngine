#include "window.hpp"

using namespace rha;
cWindow::cWindow(glm::vec2 size, const std::string& title, cLogger& logger) :run(1){
    if(!glfwInit()) logger<<"ERROR: Failed to load GLFW!\n";

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //MacOS needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    handle=glfwCreateWindow( size.x, size.y, title.c_str(), NULL, NULL);
    if(handle==NULL){
        logger<<"ERROR: Failed to open GLFW window! If you have an Intel GPU, they are not 3.3 compatible.\n";
        cWindow::close();
    } glfwMakeContextCurrent(handle);
    if(glewInit()!=GLEW_OK) logger<<"ERROR: Failed to load GLEW!\n";
}
