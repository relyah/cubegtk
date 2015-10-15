#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include <vector>

#include "IKeyReleasedListener.h"
#include "IScrollListener.h"

typedef  std::vector<IKeyReleasedListener*> TKeyReleasedListeners;
typedef  std::vector<IScrollListener*> TScrollListeners;

class InputManager : public IKeyReleasedListener, public IScrollListener {

public:
  InputManager();
  virtual ~InputManager();

  virtual void OnKeyReleased(int key);
  virtual void OnScroll(GdkScrollDirection dir);

  void RegisterListener(IKeyReleasedListener *l);
  void RegisterListener(IScrollListener *l);

private:
  TKeyReleasedListeners keyReleasedListeners;
  TScrollListeners scrollListeners;

};

#endif
