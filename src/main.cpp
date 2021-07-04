#include "GL/glew.h"
#include "GL/freeglut.h"
#include <cmath>
#include <vector>
#include <algorithm>

class Shape {
public:
  virtual void prepareBuffer() = 0;
  virtual ~Shape() {}
};

class Triangle : public Shape {
public:
  Triangle() = default;
  ~Triangle() override = default;
  void prepareBuffer() override {
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-0.67f, -1.0f, 0.0f);
    glVertex3f(-0.83f, -0.33f, 0.0f);
    glEnd();
  }
};

class Square : public Shape {
public:
  Square() = default;
  ~Square() override = default;
  void prepareBuffer() override {
    glBegin(GL_QUADS);
    glVertex3f(-0.66f, -1.0f, 0.0f);
    glVertex3f(-0.33f, -1.0f, 0.0f);
    glVertex3f(-0.33f, -0.33f, 0.0f);
    glVertex3f(-0.66f, -0.33f, 0.0f);
    glEnd();
  }
};

class myEllipse : public Shape {
public:
  myEllipse() = default;
  ~myEllipse() override = default;
  void prepareBuffer() override {
    glBegin(GL_LINE_LOOP);
    for (std::size_t i = 0; i < 300; ++i) {
      double angle = 2.0 * 3.14 * i / 300;
      double x = 0.33 * cos(angle);
      double y = 0.33 * sin(angle);
      glVertex2d(x, -0.67f + y);
    }
    glEnd();
  }
};

static void RenderCallback() {
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

  glClear(GL_COLOR_BUFFER_BIT);
  glColor4f(1, 1, 1, 1);

  std::vector<Shape*> shapes;
  Triangle t;
  shapes.push_back(&t);
  Square s;
  shapes.push_back(&s);
  myEllipse e;
  shapes.push_back(&e);

  std::for_each(shapes.begin(), shapes.end(), [](Shape* s) { s->prepareBuffer(); });

  glutDisplayFunc(&RenderCallback);
  glutMainLoop();
  return 0;
}