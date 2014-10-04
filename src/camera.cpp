#include "camera.hpp"

using namespace rha;
cCamera::cCamera(glm::vec3 position, float FoV){
    this->position=position;
    this->FoV=FoV;

    horizontalAngle=0.0f;
    verticalAngle=0.0f;
} void cCamera::update(cWindow* window, cMouse* mouse, cKeyboard* keyboard){
    horizontalAngle+=0.0035f*float((window->getSize().x/2)-mouse->getPosition().x);
	verticalAngle+=0.0020f*float((window->getSize().y/2)-mouse->getPosition().y);

    direction=glm::vec3(cos(verticalAngle)*sin(horizontalAngle), sin(verticalAngle),cos(verticalAngle)*cos(horizontalAngle));
    right=glm::vec3(sin(horizontalAngle-3.14f/2.0f), 0, cos(horizontalAngle-3.14f/2.0f));
    up=glm::cross(right, direction);

    projection=glm::perspective(FoV, static_cast<float>(window->getSize().x/window->getSize().y), 0.1f, 100.0f);
    view=glm::lookAt(position, position+direction, up);
}
