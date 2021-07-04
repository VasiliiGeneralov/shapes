#include "GL/glew.h"
#include "GL/freeglut.h"

static GLuint VBO;

static void CreateVertexBuffer() {
  double coordinates[3];
  coordinates[0] = 0.0f;
  coordinates[1] = 0.0f;
  coordinates[2] = 0.0f;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(coordinates), coordinates, GL_STATIC_DRAW);
}

static void RenderCallback() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glDrawArrays(GL_POINTS, 0, 1);
  glDisableVertexAttribArray(0);
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(500, 200);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("test shapes");
  GLenum res = glewInit();
  if (res != GLEW_OK) {
    return 1;
  }
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  CreateVertexBuffer();
  glutDisplayFunc(&RenderCallback);
  glutMainLoop();
  return 0;
}