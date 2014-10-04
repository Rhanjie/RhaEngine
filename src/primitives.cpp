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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), reinterpret_cast<GLvoid*>(0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), reinterpret_cast<GLvoid*>(sizeof(glm::vec3)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sVertex), reinterpret_cast<GLvoid*>(sizeof(glm::vec3)*2));

    glBindVertexArray(0);
}
cPrimitive::~cPrimitive(){
    glDeleteBuffers(1, &vboID );
	glDeleteVertexArrays(1, &vaoID );
} cPrimitive::cPrimitive(GLenum type) :vboID(0), vaoID(0){
    this->model=glm::mat4();
    this->type=type;

	createVbo();
}

void cPrimitive::addVertex(glm::vec3 position, glm::vec4 color){
    sVertex vertex={position.x, position.y, position.z, color.x, color.y, color.z, color.w};
    v_vertex.push_back(vertex);
}
void cPrimitive::build(){
	glBindVertexArray(vaoID);
	glBufferData(GL_ARRAY_BUFFER, v_vertex.size() *sizeof(sVertex), &this->v_vertex[0], GL_STATIC_DRAW);
	glBindVertexArray(NULL);
}
void cPrimitive::draw(){
    model=glm::mat4();

    glBindVertexArray(vaoID);
    glDrawArrays(type, 0, v_vertex.size());
    glBindVertexArray(0);
}
