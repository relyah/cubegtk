#include "Camera.h"

Camera::Camera(IOpenGLProgram *program, int screenWidth, int screenHeight)
  : program(program), screenWidth(screenWidth), screenHeight(screenHeight){
  logger = Logger::GetLogger();

  cameraPosition = glm::vec3(2.0, 2.0, 5.0);  // the position of your camera, in world space
  cameraLookAt = glm::vec3(0.0, 0.0, 0.0);  // where you want to look at, in world space
	cameraUp = glm::vec3(0.0, 1.0, 0.0); //up direction; probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
	//cameraRight = glm::vec3(1.0, 0.0, 0.0);

  view =   glm::lookAt(cameraPosition, cameraLookAt, cameraUp); //glm::mat4(1.0f);//

  projection =  glm::perspective(45.0f, 1.0f * screenWidth / screenHeight, 0.1f, 100.0f); //glm::mat4(1.0f);//


}

Camera::~Camera() {
  program=0;
  logger = 0;
}

void Camera::Init() {
  program->Use();
  
  uniform_v = program->GetUniform("view");
  uniform_p = program->GetUniform("projection");

  glUniformMatrix4fv(uniform_v, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(uniform_p, 1, GL_FALSE, glm::value_ptr(projection));

  sstm.str(std::string());
  sstm << "uniform v: " << uniform_v << ", p: " << uniform_p << std::endl;
  logger->info(sstm.str());
}

void Camera::Render() {
  //glUniformMatrix4fv(uniform_v, 1, GL_FALSE, glm::value_ptr(view));
  // glUniformMatrix4fv(uniform_p, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::Shutdown() {
  program=0;
}
