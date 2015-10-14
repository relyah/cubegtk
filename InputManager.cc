#include "InputManager.h"

InputManager::InputManager() {
  keyReleasedListeners = std::vector<IKeyReleasedListener*>();
}

InputManager::~InputManager() {
  keyReleasedListeners.clear();
}

void InputManager::RegisterListener(IKeyReleasedListener *l) {
  keyReleasedListeners.push_back(l);
}

void InputManager::OnKeyReleased(int key) {
  if (keyReleasedListeners.size()==0) {return;}

  for (TKeyReleasedListeners::iterator it = keyReleasedListeners.begin() ; it != keyReleasedListeners.end(); ++it) {
    (*it)->OnKeyReleased(key);
  }
  
}
