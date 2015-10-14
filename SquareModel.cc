#include "SquareModel.h"

SquareModel::SquareModel() {
  logger = Logger::GetLogger();
  isChanged = true;
}

SquareModel::~SquareModel() {
  logger = 0;
}

bool SquareModel::IsChanged() {
  return isChanged;
}

glm::mat4 SquareModel::GetModel() {

  if (isChanged) {
    logger->info("square model updated");
    matrix = glm::translate(glm::mat4(1.0f), glm::vec3(xpos,ypos,0.0f));
    isChanged = false;
  }

  return matrix;
}

void SquareModel::OnKeyReleased(int key) {
  //sstm.str(std::string());
  //sstm << "got key in SquareModel " << key << " " << GDK_KEY_KP_Left <<  std::endl;

  //logger->info(sstm.str());
  switch (key) {
  case GDK_KEY_KP_Left:
    logger->info("left");
    xpos -= xinc;
    isChanged = true;
    break;
  case GDK_KEY_KP_Up:
    ypos -= yinc;
    break;
  case GDK_KEY_KP_Right: 
    xpos += xinc;
    break;
  case GDK_KEY_KP_Down:
    ypos += yinc;
    break;
  default: break;

  }
}
