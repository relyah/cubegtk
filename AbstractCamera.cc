#include "AbstractCamera.h"

AbstractCamera::AbstractCamera() {
  view = glm::mat4(1.0f);
  projection = glm::mat4(1.0f);
}

AbstractCamera::~AbstractCamera() {

}

glm::mat4 AbstractCamera::GetView() {
  return view;
}

glm::mat4 AbstractCamera::GetProjection() {
  return projection;
}
