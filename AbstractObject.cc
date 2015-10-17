#include "AbstractObject.h"

AbstractObject::AbstractObject(IOpenGLProgram* program) : program(program)  {

}

AbstractObject::~AbstractObject() {
  program=0;
}

void AbstractObject::Gen() {
  glGenVertexArrays(1, &vao);
  Bind();
}

void AbstractObject::Bind() {
  glBindVertexArray(vao);
}

void AbstractObject::Shutdown() {
  glDeleteVertexArrays(1,&vao);
}
