#include "OpenGLApplication.h"

OpenGLApplication::OpenGLApplication(int screenWidth, int screenHeight)
  :screenWidth(screenWidth), screenHeight(screenHeight){
  logger->info("Starting OpenGLApplication...");

  manager = new OpenGLManager();
  program = new OpenGLProgram();
  inputManager = new InputManager();

  model = new SquareModel();
  square = new Square(program, model);
  camera = new Camera(program, screenWidth, screenHeight);

  program->SetCamera(camera);
  program->AddObject(square);

  inputManager->RegisterListener(model);

}

OpenGLApplication::~OpenGLApplication() {
  delete square;
  delete model;
  delete camera;
  delete program;
  delete manager;
  delete inputManager;
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

void OpenGLApplication::OnKeyReleased(int key) {
  inputManager->OnKeyReleased(key);
}
