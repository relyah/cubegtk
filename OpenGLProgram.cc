#include "OpenGLProgram.h"

OpenGLProgram::OpenGLProgram() {
  logger->info("Starting OpenGLProgram...");

  objects = TObjects();
}

OpenGLProgram::~OpenGLProgram() {
  logger->info("Stopped OpenGLProgram.");
}

void OpenGLProgram::AddObject(IObject* object) {
  objects.push_back(object);
}

void OpenGLProgram::SetCamera(Camera* camera) {
  this->camera = camera;
}

void OpenGLProgram::Init() {
  logger->info("Init OpenGLProgram...");

  InitProgram();

  camera->Init();
  InitObjects();
}

void OpenGLProgram::InitObjects() {
  if (objects.size()==0) {return;}

  for (TObjects::iterator it = objects.begin() ; it != objects.end(); ++it) {
    (*it)->Init();
  }
}

void OpenGLProgram::Render() {

  //logger->info("Program rendering...");

  Use();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.1, 0.0, 1.0);
  glPointSize(40.0f);

  camera->Render();
  RenderObjects();

  glBindVertexArray (0);
  glUseProgram (0);

  glFlush();
}

void OpenGLProgram::RenderObjects() {
  if (objects.size()==0) {return;}

  for (TObjects::iterator it = objects.begin() ; it != objects.end(); ++it) {
    (*it)->Render();
  }
}

void OpenGLProgram::Shutdown() {

  camera->Shutdown();
  camera=0;

  ShutdownObjects();

  glUseProgram(0);

  glDetachShader(GetProgram(), vs);
  glDetachShader(GetProgram(), fs);

  glDeleteShader(fs);
  glDeleteShader(vs);

  objects.clear();

  AbstractOpenGLProgram::Shutdown();//  glDeleteProgram(GetProgram());
}

void OpenGLProgram::ShutdownObjects() {
  if (objects.size()==0) {return;}

  for (TObjects::iterator it = objects.begin() ; it != objects.end(); ++it) {
    (*it)->Shutdown();
  }

  objects.clear();
}

void OpenGLProgram::InitProgram() {
  CreateProgram("cube.vs.glsl","cube.fs.glsl",vs,fs);

  sstm.str(std::string());
  sstm << "program: " << program << std::endl;
  logger->info(sstm.str());
}

/*
  void OpenGLProgram::InitVAO() {

  /*GLfloat verts[] = 
  {
  +0.0f, +1.0f,
  -1.0f, -1.0f,
  +1.0f, -1.0f,
  };
*/
//GenVAO();
//glGenVertexArrays(1, &vao);
//glBindVertexArray(vao);

/*glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glBindVertexArray(0);

  glDeleteBuffers(1, &vbo);*/
//}

