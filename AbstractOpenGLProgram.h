#ifndef _ABSTRACTOPENGLPROGRAM_H_
#define _ABSTRACTOPENGLPROGRAM_H_

#include <epoxy/gl.h>

#include "AdminBase.h"

class AbstractOpenGLProgram : public AdminBase {
protected:
  GLuint CreateProgram(const char *vertexfile, const char *fragmentfile, GLuint &vshader, GLuint &fshader);
  GLuint CreateShader(GLenum type, const char *filename);
  GLint GetAttrib(GLuint program, const char *name);
  GLint GetUniform(GLuint program, const char *name);
private:
  char* file_read(const char* filename);
  void print_log(GLuint object);
};

#endif
