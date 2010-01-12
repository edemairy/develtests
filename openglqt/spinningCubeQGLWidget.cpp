#include <QApplication>
#include "SpinningCubeQGLWidget.h"
#include <GL/glut.h>

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  // Create a Qt application
  QApplication app( argc, argv );
  // create a new OpenGL Qt window
  QGLWidget* gl = new DrawTriangleGLWidget((QWidget*)0);

  gl->show();
  return app.exec();
}
