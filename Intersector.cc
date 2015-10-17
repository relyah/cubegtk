#include "Intersector.h"

Intersector::Intersector(ICamera *camera) :
  camera(camera),
  isPressed(false){
}

Intersector::~Intersector() {
  camera = 0;
}

void Intersector::OnDrag(double x, double y) {

}

void Intersector::OnButtonPressed(int button, double x, double y) {
  isPressed = true;
}

void Intersector::OnButtonReleased(int button, double x, double y) {

}
