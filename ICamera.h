#ifndef _ICAMERA_H_
#define _ICAMERA_H_

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ICamera {

public:
  virtual ~ICamera() {};

  virtual glm::mat4 GetView() = 0;
  virtual glm::mat4 GetProjection() = 0;

};
#endif
