#ifndef _SQUARE_H_
#define _SQUARE_H_

#inclide "Logger.h"
#include "DataStructures.h"
#include "IObject.h"
#include "IOpenGLProgram.h"
#include "IModel.h"

class Square : IObject {

public:

  Square(IOpenGLProgram* program, IModel* model);
  ~Square();

  void Init();
  void FillVBO();
  void Render();
  void Shutdown();

private:
  log4cpp::Category* logger;
  IOpenGLProgram* program;
  IModel* model;

  GLuint vboPoints;
  GLuint iboPoints;
  GLuint attribute_vp, attribute_vn, attribute_vc;
  GLint uniform_m;

};

#endif
