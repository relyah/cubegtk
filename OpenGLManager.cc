#include "OpenGLManager.h"

OpenGLManager::OpenGLManager() {
  logger = Logger::GetLogger();
  logger->info("Starting OpenGLManager...");
}

OpenGLManager::~OpenGLManager() {
  logger->info("Stopping down OpenGL.");
	logger->info("Stopped OpenGL.");
	logger = 0;
}
