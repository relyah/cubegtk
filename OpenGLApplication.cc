#include "OpenGLApplication.h"

OpenGLApplication::OpenGLApplication() {
  logger->info("Starting OpenGLApplication...");
}

OpenGLApplication::~OpenGLApplication() {
  logger->info("Stopped OpenGLApplication.");
  logger = 0;
}

void OpenGLApplication::Init() {
  logger->info("Init OpenGLApplication...");
}

void OpenGLApplication::Render() {
  logger->info("Render OpenGLApplication...");
}

void OpenGLApplication::Shutdown() {
  logger->info("Shutdown OpenGLApplication...");
}
