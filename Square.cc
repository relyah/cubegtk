#include "Square.h"

Square::Square(IOpenGLProgram* program, IModel* model) : AbstractObject(program,model) {
  //logger = Logger::GetLogger();
  points[0] = {    0.5f,  0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
  points[1] = {  0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
  points[2] = {   -0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
  points[3] = {   -0.5f, 0.5f, 0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
}

Square::~Square() {
  model=0;
  //logger=0;
}

void Square::Init() {

  Gen();

  attribute_vp = program->GetAttrib("vp");
  attribute_vn = program->GetAttrib("vn");
  attribute_vc = program->GetAttrib("vc");

  uniform_m = program->GetUniform("model");
  uniform_v = program->GetUniform("view");
  uniform_p = program->GetUniform("projection");

  sstm.str(std::string());
  sstm << "attributes vp: " << attribute_vp << ", vn: " << attribute_vn << ", vc: " << attribute_vc << ", uniform m: " << uniform_m  << ", uniform_p: " << uniform_p << std::endl;
  logger->info(sstm.str());

  FillVBO();
}

void Square::Gen() {
  AbstractObject::Gen();
  //glGenVertexArrays(1, &vao);
  //glBindVertexArray(vao);
  glGenBuffers(1, &vboPoints);
}

void Square::FillVBO() {

  unsigned short pointsIndex[] = {0,1,2,2,3,0};

  //glUseProgram(program->GetProgram());
  //program->GenVAO();

  //glGenBuffers(1, &vboPoints);
  glBindBuffer(GL_ARRAY_BUFFER, vboPoints);
  sstm.str(std::string());
  sstm << "vboPoints: " << vboPoints << std::endl;
  logger->info(sstm.str());
  glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(VertexStructure), points, GL_STATIC_DRAW);

  glGenBuffers(1, &iboPoints);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboPoints);
  sstm.str(std::string());
  sstm << "iboPoints: " << iboPoints << std::endl;
  logger->info(sstm.str());
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,6*sizeof(unsigned short), pointsIndex, GL_STATIC_DRAW);

  glEnableVertexAttribArray(attribute_vp);
  glVertexAttribPointer (attribute_vp, 3, GL_FLOAT, GL_FALSE, sizeof(VertexStructure), (GLubyte*)NULL);

  glEnableVertexAttribArray(attribute_vn);
  glVertexAttribPointer(attribute_vn, 3, GL_FLOAT, GL_FALSE, sizeof(VertexStructure),(GLvoid*)offsetof(struct VertexStructure, normal));

  glEnableVertexAttribArray(attribute_vc);
  glVertexAttribPointer(attribute_vc, 3, GL_FLOAT, GL_FALSE, sizeof(VertexStructure),(GLvoid*)offsetof(struct VertexStructure, colour));
}

void Square::Render() {
  Bind();

//  if (model->IsChanged()) {
  //logger->info("Square updating...");
  glm::mat4 modelMatrix = model->GetModel();
  glUniformMatrix4fv(uniform_m,1,GL_FALSE,glm::value_ptr(modelMatrix));

  glm::mat4 viewMatrix = model->GetView();
  glUniformMatrix4fv(uniform_v,1,GL_FALSE,glm::value_ptr(viewMatrix));

  glm::mat4 projectionMatrix = model->GetProjection();
  glUniformMatrix4fv(uniform_p,1,GL_FALSE,glm::value_ptr(projectionMatrix));
//  }

  sstm.str(std::string());
  sstm << "vboPoints: " << vboPoints << std::endl;
  logger->info(sstm.str());
  
  //glBindBuffer(GL_ARRAY_BUFFER, vboPoints);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboPoints);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Square::Shutdown() {
  AbstractObject::Shutdown();
  program=0;
  model=0;
  //glDeleteVertexArrays(1,&vao);
}

void Square::Intersect(Ray &ray) {
  logger->info("doing hard work...");

  glm::mat4 modelMatrix = model->GetModel();
  glm::mat4 view = model->GetView();

  VertexStructure points[4];
  points[0] = {    0.5f,  0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
  points[1] = {  0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
  points[2] = {   -0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};
  points[3] = {   -0.5f, 0.5f, 0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f};

  //make plane
  /*glm::vec4 a = ( glm::vec4(points[0].coord3d[0],points[0].coord3d[1],points[0].coord3d[2],1.0f));
  glm::vec4 b =( glm::vec4(points[1].coord3d[0],points[1].coord3d[1],points[1].coord3d[2],1.0f));
  glm::vec4 c = ( glm::vec4(points[2].coord3d[0],points[2].coord3d[1],points[2].coord3d[2],1.0f));
  glm::vec4 d = ( glm::vec4(points[3].coord3d[0],points[3].coord3d[1],points[3].coord3d[2],1.0f));*/

  glm::vec4 a = ( glm::vec4(  0.5f,  0.5f,  0.0f,1.0f));
  glm::vec4 b =( glm::vec4( 0.5f, -0.5f,  0.0f,1.0f));
  glm::vec4 c = ( glm::vec4( -0.5f, -0.5f,  0.0f,1.0f));
  glm::vec4 d = ( glm::vec4(  -0.5f, 0.5f, 0.0f,1.0f));

  DebugPrint("a",a);
  DebugPrint("b",b);
  DebugPrint("c",c);
  DebugPrint("d",d);

  Plane p("test",a,b,c,d);

  //test for intersection
  //if (p.Intersect(ray)) {
  //  logger->info("hit");
  //}

}
