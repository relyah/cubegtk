#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include <vector>

#include "IKeyReleasedListener.h"

typedef  std::vector<IKeyReleasedListener*> TKeyReleasedListeners;

class InputManager : public IKeyReleasedListener {

public:
  InputManager();
  virtual ~InputManager();

  virtual void OnKeyReleased(int key);
  void RegisterListener(IKeyReleasedListener *l);

private:
  std::vector<IKeyReleasedListener*> keyReleasedListeners;

};

#endif
