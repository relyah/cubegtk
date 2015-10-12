#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "IOpenGLProgram.h"

class Square {

public:
  void FillVBO();

private:
  IOpenGLProgram* program;

};

#endif
