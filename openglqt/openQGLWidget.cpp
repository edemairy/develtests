#include <QApplication>
#include <QGLWidget>
int main(int argc, char** argv) {
  // Create a Qt application
  QApplication app( argc, argv );
  // create a new OpenGL Qt window
  QGLWidget* gl = new QGLWidget((QWidget*)0);
  gl->show();
  return app.exec();
}