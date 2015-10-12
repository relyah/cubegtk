#ifndef OPENGPROGRAM_H_
#define OPENGLPROGRAM_H_

#include "AbstractOpenGLProgram.h"

class OpenGLProgram : public AbstractOpenGLProgram {

public:
  OpenGLProgram();
  ~OpenGLProgram();

  void AddObject(IObject* object);

  void Init();
  void Render();
  void Shutdown();

private:
  GLuint vao, vbo;
  GLuint vs, fs;
  IObject* object;

  void InitProgram();
  void InitVAO();
};

#endif

