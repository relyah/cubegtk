#include "OpenGLApplication.h"

OpenGLApplication::OpenGLApplication() {
  logger->info("Starting OpenGLApplication...");

  manager = new OpenGLManager();
  program = new OpenGLProgram();

  model = new SquareModel();
  square = new Square(&program, &model);

  program->AddObject(square);
}

OpenGLApplication::~OpenGLApplication() {
  delete square;
  delete model;
  delete program;
  delete manager;
  logger->info("Stopped OpenGLApplication.");
  logger = 0;
}

void OpenGLApplication::Init() {
  logger->info("Init OpenGLApplication...");

  manager->Init(manager);
  program->Init();
}

void OpenGLApplication::Render() {
  logger->info("Render OpenGLApplication...");

  program->Render();
}

void OpenGLApplication::Shutdown() {
  logger->info("Shutdown OpenGLApplication...");
}
