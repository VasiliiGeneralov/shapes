#include "GL/freeglut.h"

static void RenderCallback() {
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(500, 200);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("test shapes");
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glutDisplayFunc(&RenderCallback);
  glutMainLoop();
  return 0;
}