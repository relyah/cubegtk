#ifndef _OPENGLAPPLICATION_H_
#define _OPENGLAPPLICATION_H_

#include "AdminBase.h"

class OpenGLApplication : public AdminBase {
public:
  OpenGLApplication();
  ~OpenGLApplication();

  void Init();
  void Render();
  void Shutdown();

};

#endif
