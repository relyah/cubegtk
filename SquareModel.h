#ifndef _SQUAREMODEL_H_
#define _SQUAREMODEL_H_

#include <gdk/gdkkeysyms.h>

#include "Logger.h"
#include "IModel.h"
#include "IKeyReleasedListener.h"


class SquareModel: public IModel, public IKeyReleasedListener {

public:
  SquareModel();
  ~SquareModel();

  glm::mat4 GetModel();
  bool IsChanged();

  virtual void OnKeyReleased(int key);

private:
  //std::stringstream sstm;
  log4cpp::Category* logger;
  bool isChanged;
  glm::mat4 matrix;
  float xinc = 0.1f, yinc=0.1f;
  float xpos = 0.0f, ypos=0.0f;
};

#endif
