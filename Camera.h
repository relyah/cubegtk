#ifndef _CAMERA_H_
#define _CAMERA_H_

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <epoxy/gl.h>

#include "Logger.h"
#include "IOpenGLProgram.h"
#include "IScrollListener.h"
#include "IDragListener.h"
#include "IButtonPressedListener.h"
#include "IButtonReleasedListener.h"

class Camera : public IScrollListener, public IDragListener, public IButtonPressedListener, public IButtonReleasedListener {

public:
  Camera(IOpenGLProgram *program, int screenWidth, int screenHeight);
  virtual ~Camera();

  void Init();
  void Render();
  void Shutdown();

  void OnScroll(GdkScrollDirection dir);
  void OnDrag(double x, double y);
  void OnButtonPressed(int button, double x, double y);
  void OnButtonReleased(int button, double x, double y);

private:
  std::stringstream sstm;
  log4cpp::Category* logger;
  IOpenGLProgram *program;
  int screenWidth;
  int screenHeight;
  GLint uniform_p;
  GLint uniform_v;
  bool isCameraUpdated;
  bool isCameraMoving;
  glm::vec3 cameraPosition, cameraOrigPos;
  glm::vec3 cameraLookAt;
  glm::vec3 cameraUp;
  glm::mat4 view;
  glm::mat4 projection;
  float zoomDelta;
  glm::vec2 cursor;
  glm::vec2 cameraRotate;

  void ZoomCamera();

};

#endif

