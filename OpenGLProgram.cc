#include "OpenGLProgram.h"

OpenGLProgram::OpenGLProgram() {
  logger->info("Starting OpenGLProgram...");
}

OpenGLProgram::~OpenGLProgram() {
  logger->info("Stopped OpenGLProgram.");
}

void OpenGLProgram::AddObject(IObject* object) {
  this->object = object;
}

void OpenGLProgram::Init() {
  logger->info("Init OpenGLProgram...");

  InitProgram();
  object->Init();
  InitVAO();
  object->FillVBO();
}

void OpenGLProgram::Render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);

  glUseProgram(GetProgram());
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  object->Render();

  glBindVertexArray (0);
  glUseProgram (0);

  glFlush();
}

void OpenGLProgram::Shutdown() {
  object->ShutDown();
  object=0;
  
  glUseProgram(0);

  glDetachShader(GetProgram(), vs);
  glDetachShader(GetProgram(), fs);

  glDeleteShader(fs);
  glDeleteShader(vs);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  AbstractOpenGLProgram::Shutdown();//  glDeleteProgram(GetProgram());
}

void OpenGLProgram::InitProgram() {
  CreateProgram("vs.glsl","fs.glsl",vs,fs);
}

void OpenGLProgram::InitVAO() {

  GLfloat verts[] = 
    {
      +0.0f, +1.0f,
      -1.0f, -1.0f,
      +1.0f, -1.0f,
    };

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glBindVertexArray(0);

  glDeleteBuffers(1, &vbo);
}
