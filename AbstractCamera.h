#ifndef _ABSTRACTCAMERA_H_
#define _ABSTRACTCAMERA_H_

#include "ICamera.h"

class AbstractCamera : public ICamera {

public:
  AbstractCamera();
  virtual ~AbstractCamera();

  virtual glm::mat4 GetView();
  virtual glm::mat4 GetProjection();

protected:
  glm::mat4 view;
  glm::mat4 projection;


};
#endif
