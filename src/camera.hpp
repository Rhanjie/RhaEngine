#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED
#include "managerLibs.hpp"
#include "logger.hpp"
#include "window.hpp"
#include "input.hpp"

namespace rha{
    class cCamera{
        private:
         glm::vec3 position,
            direction, right, up;
         GLfloat horizontalAngle, FoV,
            verticalAngle;

         glm::mat4 view, projection;
        public:
         cCamera(glm::vec3 position, GLfloat FoV);
         void update(rha::cWindow* window, rha::cMouse* mouse, rha::cKeyboard* keyboard);

         inline void move(GLfloat speed){position+=direction*speed;}
         inline void rotate(GLfloat angle){position+=right*angle;}
         inline glm::mat4 &getProjection(){return projection;}
         inline glm::mat4 &getView(){return view;}
    };
}

#endif // CAMERA_HPP_INCLUDED
