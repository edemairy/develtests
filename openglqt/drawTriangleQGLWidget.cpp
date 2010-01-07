#include <QApplication>
#include "DrawTriangleGLWidget.h"


int main(int argc, char** argv) {
  // Create a Qt application
  QApplication app( argc, argv );
  // create a new OpenGL Qt window
  QGLWidget* gl = new DrawTriangleGLWidget((QWidget*)0);
  gl->show();
  return app.exec();
}