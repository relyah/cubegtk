#ifndef OPENGLMANAGER_H_
#define OPENGLMANAGER_H_

#include <epoxy/gl.h>

#include "AdminBase.h"

class OpenGLManager : public AdminBase {

public:
  OpenGLManager();
  ~OpenGLManager();

  void Init();

};


#endif
