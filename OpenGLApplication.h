#ifndef _OPENGLAPPLICATION_H_
#define _OPENGLAPPLICATION_H_

#include "AdminBase.h"
#include "OpenGLManager.h"
#include "OpenGLProgram.h"
#include "IObject.h"
#include "Square.h"
#include "IModel.h"
#include "SquareModel.h"

class OpenGLApplication : public AdminBase {
public:
  OpenGLApplication();
  ~OpenGLApplication();

  void Init();
  void Render();
  void Shutdown();

private:
  OpenGLManager *manager;
  OpenGLProgram *program;
  IObject *square;
  IModel *model;
};

#endif
