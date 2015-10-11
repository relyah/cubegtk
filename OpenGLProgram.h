#ifndef OPENGPROGRAM_H_
#define OPENGLPROGRAM_H_

#include <epoxy/gl.h>

#include "AdminBase.h"

class OpenGLProgram : public AdminBase {

public:
  OpenGLProgram();
  ~OpenGLProgram();

  void Init();
  void Render();
  void Shutdown();

private:
  GLuint vao, vbo, program;
  GLuint vs, fs;

  void InitProgram();
  void InitVAO();
};

#endif

