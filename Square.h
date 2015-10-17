#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Logger.h"
#include "DataStructures.h"
#include "IObject.h"
#include "AbstractObject.h"
#include "IOpenGLProgram.h"
#include "IModel.h"
#include "IHitable.h"
#include "Ray.h"
#include "Plane.h"

class Square  : public AbstractObject, public IHitable {

public:

  Square(IOpenGLProgram* program, IModel* model);
  virtual ~Square();

  void Init();
  void Render();
  virtual void Shutdown();

  virtual void Intersect(Ray &ray);

private:
  //std::stringstream sstm;
  //log4cpp::Category* logger;

  GLuint vboPoints;
  GLuint iboPoints;
  GLuint attribute_vp, attribute_vn, attribute_vc;
  GLint uniform_m;
  GLint uniform_v;
  GLint uniform_p;

  VertexStructure points[4];

  virtual void Gen();
  void FillVBO();
};

#endif
