#include "primitives.hpp"

using namespace rha;
void cPrimitive::createVbo(){
    glGenBuffers(1, &vboID);
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), VERTEXBUFFER_OFFSET(0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), VERTEXBUFFER_OFFSET(sizeof(glm::vec3)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sVertex), VERTEXBUFFER_OFFSET(sizeof(glm::vec3)*2));
    glBindVertexArray(0);
}
cPrimitive::~cPrimitive(){
    glDeleteBuffers(1, &vboID );
	glDeleteVertexArrays(1, &vaoID );
} cPrimitive::cPrimitive(GLenum type) :vboID(0), vaoID(0){
    this->type=type;
	createVbo();
}

void cPrimitive::build(){
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindVertexArray(vaoID);
	glBufferData(GL_ARRAY_BUFFER, v_vertex.size() *sizeof(sVertex), &this->v_vertex[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindVertexArray(NULL);
}
void cPrimitive::draw(){
    glBindVertexArray(vaoID);
    glDrawArrays(type, 0, v_vertex.size());
    glBindVertexArray(0);
}

void cPrimitive::addVertex(glm::vec3 position){
    sVertex vertex={position.x, position.y, position.z};
    v_vertex.push_back(vertex);
}
