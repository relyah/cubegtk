#ifndef _IOBJECT_H_
#define _IOBJECT_H_

class IObject {
public:

  virtual ~IObject() {}

  virtual void Gen() = 0;
  virtual void Init() = 0;
  //virtual void FillVBO() = 0;
  virtual void Render() = 0;
  virtual void Shutdown() = 0;
};

#endif
