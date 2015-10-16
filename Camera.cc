#include "Camera.h"

Camera::Camera(IOpenGLProgram *program, int screenWidth, int screenHeight)
  : program(program), screenWidth(screenWidth), screenHeight(screenHeight){
  logger = Logger::GetLogger();

  cameraPosition = cameraOrigPos = glm::vec3(0.0, 0.0, 5.0);  // the position of your camera, in world space
  cameraLookAt = glm::vec3(0.0, 0.0, 0.0);  // where you want to look at, in world space
	cameraUp = glm::vec3(0.0, 1.0, 0.0); //up direction; probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
	//cameraRight = glm::vec3(1.0, 0.0, 0.0);

  cameraRotate = glm::vec2(0.0f, 0.0f);

  view =   glm::lookAt(cameraPosition, cameraLookAt, cameraUp); //glm::mat4(1.0f);//

  projection =  glm::perspective(45.0f, 1.0f * screenWidth / screenHeight, 0.1f, 100.0f); //glm::mat4(1.0f);//


}

Camera::~Camera() {
  program=0;
  logger = 0;
}

void Camera::Init() {
  isCameraUpdated = true;
  program->Use();
  
  uniform_v = program->GetUniform("view");
  uniform_p = program->GetUniform("projection");

  //glUniformMatrix4fv(uniform_v, 1, GL_FALSE, glm::value_ptr(view));
  //glUniformMatrix4fv(uniform_p, 1, GL_FALSE, glm::value_ptr(projection));

  sstm.str(std::string());
  sstm << "uniform v: " << uniform_v << ", p: " << uniform_p << std::endl;
  logger->info(sstm.str());
}

void Camera::Render() {
  if (isCameraUpdated) {
    isCameraUpdated = false;
    view =   glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
    glUniformMatrix4fv(uniform_v, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(uniform_p, 1, GL_FALSE, glm::value_ptr(projection));
  }
}

void Camera::Shutdown() {
  program=0;
}

void Camera::OnScroll(GdkScrollDirection dir) {
  //float  zoomDelta = 0.0f;

  if (dir==GDK_SCROLL_UP) {
    zoomDelta = 0.1f;
  } else if (dir==GDK_SCROLL_DOWN) {
    zoomDelta = -0.1f;
  } else {
    return;
  }

  ZoomCamera();

  isCameraUpdated = true;
}

void Camera::OnDrag(double x, double y) {
  if (isCameraMoving) {


    //logger->info("drag");

    //sstm.str(std::string());
    //sstm << "x2: " << x  << " y2: " << y << " x1: " << cursor.x  << " y1: " << cursor.y << std::endl;
    //logger->info(sstm.str());

    glm::vec2 delta = (glm::vec2(x,y) - cursor);

    //sstm.str(std::string());
    //sstm << "dx: " << delta.x  << " dy: " << delta.y << std::endl;
    //logger->info(sstm.str());

    cameraRotate += glm::vec2(0.1f*delta.x, 0.1f*delta.y);

    //sstm.str(std::string());
    //sstm << "cr.X: " << cameraRotate.x  << " cr.Y: " << cameraRotate.y << std::endl;
    //logger->info(sstm.str());

    glm::mat4 rot = glm::mat4(1.0f);
    float rad = glm::radians(cameraRotate.x);

    //sstm.str(std::string());
    //sstm << "rad: " << rad << std::endl;
    //logger->info(sstm.str());

    //sstm << "rad: " << rad  << std::endl;
    //logger->info(sstm.str());
    rot = glm::rotate(rot,rad,glm::vec3(0.0,1.0f,0.0));
    cameraPosition = glm::vec3(rot * glm::vec4(cameraOrigPos,1.0f));
    ZoomCamera();

    //cameraPosition += glm::vec3(0.01f*(float)delta.x,0.0f,0.0f); //0.01f*(float)delta.y

    

    cursor = glm::vec2(x,y);
    isCameraUpdated = true;
  }
}

void Camera::OnButtonPressed(int button, double x, double y) {
  isCameraMoving =  button==1;
  if(isCameraMoving) {
    //logger->info("camera moving...");
    cursor = glm::vec2(x,y);
  }
}

void Camera::OnButtonReleased(int button, double x, double y) {
  isCameraMoving = !(button==1);
  //logger->info("released");
}

void Camera::ZoomCamera() {
  glm::vec3 d = zoomDelta*glm::normalize(cameraLookAt - cameraPosition);
  cameraPosition = cameraPosition +  d;
}
