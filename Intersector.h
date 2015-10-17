#ifndef _INTERSECTOR_H_
#define _INTERSECTOR_H_

#include "ICamera.h"
#include "IDragListener.h"
#include "IButtonPressedListener.h"
#include "IButtonReleasedListener.h"

class Intersector : public IButtonPressedListener, public IButtonReleasedListener, public IDragListener {

public:
  Intersector(ICamera *camera);
  virtual ~Intersector();

  virtual void OnDrag(double x, double y);
  virtual void OnButtonPressed(int button, double x, double y);
  virtual void OnButtonReleased(int button, double x, double y);

private:
  ICamera *camera;

  bool isPressed;
};

#endif
