#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Logger.h"
#include "DataStructures.h"
#include "IObject.h"
#include "AbstractObject.h"
#include "IOpenGLProgram.h"
#include "IModel.h"

class Square  : public AbstractObject {

public:

  Square(IOpenGLProgram* program, IModel* model);
  virtual ~Square();

  void Init();
  void Render();
  void Shutdown();

private:
  std::stringstream sstm;
  log4cpp::Category* logger;
  IModel* model;

  GLuint vboPoints;
  GLuint iboPoints;
  GLuint attribute_vp, attribute_vn, attribute_vc;
  GLint uniform_m;
  GLint uniform_v;
  GLint uniform_p;

  virtual void Gen();
  void FillVBO();
};

#endif
