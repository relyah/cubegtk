#include "Square.h"

Square::Square(IOpenGLProgram* program, IModel* model) : program(program), model(model) {
  logger = Logger::GetLogger();
}

Square::~Square() {
  program=0;
  model=0;
  logger=0;
}

void Square::Init() {

  program->Use();

  attribute_vp = program->GetAttrib("vp");
  attribute_vn = program->GetAttrib("vn");
  attribute_vc = program->GetAttrib("vc");

  uniform_m = program->GetUniform("model");

  sstm.str(std::string());
  sstm << "attributes vp: " << attribute_vp << ", vn: " << attribute_vn << ", vc: " << attribute_vc << ", uniform m: " << uniform_m << std::endl;
  logger->info(sstm.str());
}

void Square::FillVBO() {
  VertexStructure points[] = {
    0.5f,  0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f,
    0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f,
    -0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f,
    -0.5f, 0.5f, 0.0f, 0.0f,0.0f,1.0f, 1.0f,0.0f,0.0f
  };
  unsigned short pointsIndex[] = {0,1,2,2,3,0};

  //glUseProgram(program->GetProgram());
  //program->GenVAO();

  glGenBuffers(1, &vboPoints);
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
  glm::mat4 modelMatrix = model->GetModel();
  glUniformMatrix4fv(uniform_m,1,GL_FALSE,glm::value_ptr(modelMatrix));

  glBindBuffer(GL_ARRAY_BUFFER, vboPoints);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboPoints);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Square::Shutdown() {
  program=0;
  model=0;
}

