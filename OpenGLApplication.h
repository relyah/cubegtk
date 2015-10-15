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
#include "IKeyReleasedListener.h"
#include "InputManager.h"

class OpenGLApplication : public AdminBase, public IKeyReleasedListener, public IScrollListener {
public:
  OpenGLApplication(int screenWidth, int screenHeight);
  virtual ~OpenGLApplication();

  void Init();
  void Render();
  void Shutdown();

  void OnKeyReleased(int key);
  void OnScroll(GdkScrollDirection dir);

private:
  int screenWidth;
  int screenHeight;
  OpenGLManager *manager;
  OpenGLProgram *program;
  IObject *square;
  SquareModel *model;
  Camera* camera;
  InputManager* inputManager;
};

#endif
