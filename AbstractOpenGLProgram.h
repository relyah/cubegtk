#ifndef _ABSTRACTOPENGLPROGRAM_H_
#define _ABSTRACTOPENGLPROGRAM_H_

#include <epoxy/gl.h>

#include "AdminBase.h"

class AbstractOpenGLProgram : public AdminBase {
protected:
  GLuint CreateShader(GLenum type, const char *filename);
  char* file_read(const char* filename);
  void print_log(GLuint object);
};

#endif