#ifndef _ICAMERA_H_
#define _ICAMERA_H_

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "IModel.h"

class ICamera : public IModel {

public:
  virtual ~ICamera() {};

};
#endif