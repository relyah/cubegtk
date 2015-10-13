#ifndef OPENGPROGRAM_H_
#define OPENGLPROGRAM_H_

#include "AbstractOpenGLProgram.h"
#include "IObject.h"
#include "Camera.h"

class OpenGLProgram : public AbstractOpenGLProgram {

public:
  OpenGLProgram();
  ~OpenGLProgram();

  void AddObject(IObject* object);

  void SetCamera(Camera* camera);

  void Init();
  void Render();
  void Shutdown();

private:
  GLuint vao, vbo;
  GLuint vs, fs;
  IObject* object;
  Camera* camera;

  void InitProgram();
  void InitVAO();
};

#endif

