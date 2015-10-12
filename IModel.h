#include _IMODEL_H_
#define _IMODEL_H_

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class IModel {

public:
  virtual glm::mat4 GetModel() = 0;
};

#endif
