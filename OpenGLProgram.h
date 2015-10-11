#ifndef OPENGPROGRAM_H_
#define OPENGLPROGRAM_H_

#include <epoxy/gl.h>

#include "AbstractOpenGLProgram.h"

class OpenGLProgram : public AbstractOpenGLProgram {

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

