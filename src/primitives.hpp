#ifndef PRIMITIVES_HPP_INCLUDED
#define PRIMITIVES_HPP_INCLUDED
#include "managerLibs.hpp"
#include "extension.hpp"

#define VERTEXBUFFER_OFFSET( i ) reinterpret_cast < GLvoid* > ( i )

namespace rha{
    class cPrimitive{
        private:
         std::vector<sVertex>v_vertex;
         GLuint vboID, vaoID;
         GLenum type;

         void createVbo();
        public:
         enum{triangle=GL_TRIANGLES,triangleStrip=GL_TRIANGLE_STRIP,
            quad=GL_QUADS, polygon=GL_POLYGON, line=GL_LINES};

         cPrimitive(GLenum type);
         ~cPrimitive();

         void build();
         void draw();

         void addVertex(glm::vec3 position);
         inline void setType();
         inline void clear();
    };
}

#endif // PRIMITIVES_HPP_INCLUDED
