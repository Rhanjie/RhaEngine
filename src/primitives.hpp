#ifndef PRIMITIVES_HPP_INCLUDED
#define PRIMITIVES_HPP_INCLUDED
#include "managerLibs.hpp"
#include "extension.hpp"

namespace rha{
    class cPrimitive{
        private:
         std::vector<sVertex>v_vertex;
         GLuint vboID, vaoID;
         glm::mat4 model;
         GLenum type;

         void createVbo();
        public:
         cPrimitive(GLenum type);
         ~cPrimitive();

         void build();
         void draw();

         inline void clear(){v_vertex.clear();}
         inline glm::mat4 &getModel(){return model;}
         inline void setType(GLenum type){this->type=type;}

         void addVertex(glm::vec3 position, glm::vec4 color);
         enum{triangle=GL_TRIANGLES,triangleStrip=GL_TRIANGLE_STRIP,
            quad=GL_QUADS, polygon=GL_POLYGON, line=GL_LINES};

         inline void move(glm::vec3 position){model=glm::translate(model, position);}
         inline void rotate(GLfloat angle){model=glm::rotate<float>(model, angle, glm::vec3(0, 1, 0));}
    };
}

#endif // PRIMITIVES_HPP_INCLUDED
