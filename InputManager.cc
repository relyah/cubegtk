#include "InputManager.h"

InputManager::InputManager() {
  keyReleasedListeners = std::vector<IKeyReleasedListener*>();
  scrollListeners = std::vector<IScrollListener*>();
}

InputManager::~InputManager() {
  keyReleasedListeners.clear();
  scrollListeners.clear();
}

void InputManager::RegisterListener(IKeyReleasedListener *l) {
  keyReleasedListeners.push_back(l);
}

void InputManager::RegisterListener(IScrollListener *l) {
  scrollListeners.push_back(l);
}

void InputManager::OnKeyReleased(int key) {
  if (keyReleasedListeners.size()==0) {return;}

  for (TKeyReleasedListeners::iterator it = keyReleasedListeners.begin() ; it != keyReleasedListeners.end(); ++it) {
    (*it)->OnKeyReleased(key);
  }
  
}

void InputManager::OnScroll(GdkScrollDirection dir) {
  if (scrollListeners.size()==0) {return;}

  for (TScrollListeners::iterator it = scrollListeners.begin() ; it != scrollListeners.end(); ++it) {
    (*it)->OnScroll(dir);
  }
  
}
