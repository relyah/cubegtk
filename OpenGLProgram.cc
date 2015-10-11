#include "OpenGLProgram.h"


const GLchar *vert_src ="\n" \
  "#version 330                                  \n" \
  "#extension GL_ARB_explicit_attrib_location: enable  \n" \
  "                                              \n" \
  "layout(location = 0) in vec2 in_position;     \n" \
  "                                              \n" \
  "void main()                                   \n" \
  "{                                             \n" \
  "  gl_Position = vec4(in_position, 0.0, 1.0);  \n" \
  "}                                             \n";

const GLchar *frag_src ="\n" \
  "void main (void)                              \n" \
  "{                                             \n" \
  "  gl_FragColor = vec4(1.0, 0.5, 1.0, 1.0);    \n" \
  "}                                             \n";

OpenGLProgram::OpenGLProgram() {
  logger->info("Starting OpenGLProgram...");
}

OpenGLProgram::~OpenGLProgram() {
  logger->info("Stopped OpenGLProgram.");
}

void OpenGLProgram::Init() {
  logger->info("Init OpenGLProgram...");

  InitProgram();
  InitVAO();
}

void OpenGLProgram::Render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);

  glUseProgram(program);
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  glBindVertexArray (0);
  glUseProgram (0);

  glFlush();
}

void OpenGLProgram::Shutdown() {
  glUseProgram(0);

  glDetachShader(program, vs);
  glDetachShader(program, fs);

  glDeleteShader(fs);
  glDeleteShader(vs);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  glDeleteProgram(program);
}

void OpenGLProgram::InitProgram() {
  fs = glCreateShader(GL_FRAGMENT_SHADER);
  vs = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(fs, 1, &frag_src, NULL);
  glShaderSource(vs, 1, &vert_src, NULL);

  glCompileShader(fs);
  glCompileShader(vs);

  program = glCreateProgram();
  glAttachShader(program, fs);
  glAttachShader(program, vs);
  glLinkProgram(program);
}

void OpenGLProgram::InitVAO() {

  GLfloat verts[] = 
    {
      +0.0f, +1.0f,
      -1.0f, -1.0f,
      +1.0f, -1.0f,
    };

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glBindVertexArray(0);

  glDeleteBuffers(1, &vbo);
}
