#include "window.hpp"

using namespace rha;
cWindow::cWindow(glm::vec2 size, const std::string& title, cLogger& logger) :run(1){
    if(!glfwInit()) logger<<"ERROR: Failed to load GLFW!\n";

    glfwWindowHint(GLFW_SAMPLES, 4);
    handle=glfwCreateWindow( size.x, size.y, title.c_str(), NULL, NULL);
    if(handle==NULL){
        logger<<"ERROR: Failed to open GLFW window! If you have an Intel GPU, they are not 3.3 compatible.\n";
        cWindow::close();
    } glfwMakeContextCurrent(handle);
    glewExperimental=GL_TRUE;
    if(glewInit()!=GLEW_OK) logger<<"ERROR: Failed to load GLEW!\n";
    logger<<"Libraries are, window is create!\n";
}
void cWindow::clear(GLclampf r, GLclampf g, GLclampf b){
    glClearColor(r/255, g/255, b/255, 255);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
