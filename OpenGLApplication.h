#ifndef _OPENGLAPPLICATION_H_
#define _OPENGLAPPLICATION_H_

#include "Logger.h"

class OpenGLApplication {
public:
  OpenGLApplication();
  ~OpenGLApplication();

  void Init();
  void Render();
  void Shutdown();

private:
  	log4cpp::Category* logger;
};

#endif
