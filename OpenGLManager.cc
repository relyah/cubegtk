#include "OpenGLManager.h"

OpenGLManager::OpenGLManager() {
  logger->info("Starting OpenGLManager...");
}

OpenGLManager::~OpenGLManager() {
	logger->info("Stopped OpenGLManager.");
}

void OpenGLManager::Init() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
}
