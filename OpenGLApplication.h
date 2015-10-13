#ifndef _OPENGLAPPLICATION_H_
#define _OPENGLAPPLICATION_H_

#include "AdminBase.h"
#include "OpenGLManager.h"
#include "OpenGLProgram.h"
#include "IObject.h"
#include "Square.h"
#include "IModel.h"
#include "SquareModel.h"
#include "Camera.h"

class OpenGLApplication : public AdminBase {
public:
  OpenGLApplication(int screenWidth, int screenHeight);
  ~OpenGLApplication();

  void Init();
  void Render();
  void Shutdown();

private:
  int screenWidth;
  int screenHeight;
  OpenGLManager *manager;
  OpenGLProgram *program;
  IObject *square;
  IModel *model;
  Camera* camera;
};

#endif
