#ifndef _CAMERA_H_
#define _CAMERA_H_

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <epoxy/gl.h>

#include "Logger.h"
#include "IOpenGLProgram.h"

class Camera {

public:
  Camera(IOpenGLProgram *program, int screenWidth, int screenHeight);
  ~Camera();

  void Init();
  void Render();
  void Shutdown();

private:
  log4cpp::Category* logger;
  IOpenGLProgram *program;
  int screenWidth;
  int screenHeight;
  GLint uniform_p;
  GLint uniform_v;
  glm::vec3 cameraPosition;
  glm::vec3 cameraLookAt;
  glm::vec3 cameraUp;
  glm::mat4 view;
  glm::mat4 projection;

};

#endif

