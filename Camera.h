#ifndef _CAMERA_H_
#define _CAMERA_H_

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <epoxy/gl.h>

#include "Logger.h"
#include "DataStructures.h"
#include "AbstractObject.h"
#include "AbstractCamera.h"
#include "IOpenGLProgram.h"
#include "IScrollListener.h"
#include "IDragListener.h"
#include "IButtonPressedListener.h"
#include "IButtonReleasedListener.h"
#include "IKeyReleasedListener.h"

class Camera :public AbstractObject, public IScrollListener, public IDragListener, public IButtonPressedListener, public IButtonReleasedListener, public IKeyReleasedListener, public AbstractCamera {

public:
  Camera(IOpenGLProgram *program, int screenWidth, int screenHeight);
  virtual ~Camera();

  void Init();
  void Render();
  void Shutdown();

  virtual void OnScroll(GdkScrollDirection dir);
  virtual void OnDrag(double x, double y);
  virtual void OnButtonPressed(int button, double x, double y);
  virtual void OnButtonReleased(int button, double x, double y);
  virtual void OnKeyReleased(int key);

  virtual int GetScreenWidth();
  virtual int GetScreenHeight();
  virtual glm::vec3 GetPosition();

private:
  std::stringstream sstm;
  log4cpp::Category* logger;
  GLuint vboPoints;
  int screenWidth;
  int screenHeight;
  GLint uniform_m;
  GLint uniform_v;
  GLint uniform_p;
  bool isCameraMoving;
  glm::vec3 cameraPosition, cameraOrigPos;
  glm::vec3 cameraLookAt;
  glm::vec3 cameraUp;
  float zoomDelta;
  glm::vec2 cursor;
  glm::vec2 cameraRotate;

  virtual void Gen();
  void ZoomCamera();
  void Reset();
  void RenderRay();
};

#endif

