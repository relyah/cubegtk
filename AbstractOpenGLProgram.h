#ifndef _ABSTRACTOPENGLPROGRAM_H_
#define _ABSTRACTOPENGLPROGRAM_H_

#include "AdminBase.h"
class AbstractOpenGLProgram : public AdminBase {
protected:
  char* file_read(const char* filename);

};

#endif
