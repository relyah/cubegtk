#include "Intersector.h"

Intersector::Intersector(ICamera *camera) :
  camera(camera),
  isPressed(false){
}

Intersector::~Intersector() {
  camera = 0;
}

void Intersector::OnDrag(double x, double y) {
  this->x=x;
  this->y=y;
}

void Intersector::OnButtonPressed(int button, double x, double y) {
  isPressed = true;
  this->x=x;
  this->y=y;
}

void Intersector::OnButtonReleased(int button, double x, double y) {
  int deltaX = abs(this->x-x);
  int deltaY = abs(this->y-y);

  //sstm.str(std::string());
  //sstm << "Intersect: dx: "<< deltaX << ", dy: " << deltaY <<std::endl;
  //logger->info(sstm.str());

  if (isPressed && deltaX==0 && deltaY==0) {
    isPressed = false;

    sstm.str(std::string());
    sstm << "Intersect: x: "<< x << ", y: " << y <<std::endl;
    logger->info(sstm.str());

    glm::vec4 rayClip = glm::vec4(1.0f);
    rayClip.x = (2.0f * (float) x) / (float) camera->GetScreenWidth() - 1.0f;
		rayClip.y = 1.0f - (2.0f * (float) y) / (float) camera->GetScreenHeight();
		rayClip.z = -1.0f;  //0.680672f;
		rayClip.w = 1.0f;

    sstm.str(std::string());
    sstm << "xp: "<< rayClip.x << ", yp: " << rayClip.y <<  ", zp: " << rayClip.z << ", wp: " << rayClip.w <<std::endl;
    logger->info(sstm.str());

    rayClip = glm::normalize(rayClip);

    sstm.str(std::string());
    sstm << "(n) xp: "<< rayClip.x << ", yp: " << rayClip.y <<  ", zp: " << rayClip.z << ", wp: " << rayClip.w <<std::endl;
    logger->info(sstm.str());

    glm::mat4 invProj = glm::inverse(camera->GetProjection());
    glm::vec4 rayEye = invProj * rayClip;
    rayEye = glm::vec4(rayEye.x, rayEye.y, -1.0f, 0.0f);

    sstm.str(std::string());
    sstm << "re x: "<< rayEye.x << ", y: " << rayEye.y <<  ", z: " << rayEye.z << ", w: " << rayEye.w <<std::endl;
    logger->info(sstm.str());

    glm::mat4 invView = glm::inverse(camera->GetView());
    glm::vec4 rayWorld = invView * rayEye;

    sstm.str(std::string());
    sstm << "rw x: "<< rayWorld.x << ", y: " << rayWorld.y <<  ", z: " << rayWorld.z << ", w: " << rayWorld.w <<std::endl;
    logger->info(sstm.str());

  }
}
