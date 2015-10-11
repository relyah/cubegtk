#include "OpenGLApplication.h"

OpenGLApplication::OpenGLApplication() {
  logger->info("Starting OpenGLApplication...");

  manager = new OpenGLManager();
}

OpenGLApplication::~OpenGLApplication() {
  delete manager;
  logger->info("Stopped OpenGLApplication.");
  logger = 0;
}

void OpenGLApplication::Init() {
  logger->info("Init OpenGLApplication...");
  
  manager->Init();
}

void OpenGLApplication::Render() {
  logger->info("Render OpenGLApplication...");
}

void OpenGLApplication::Shutdown() {
  logger->info("Shutdown OpenGLApplication...");
}
