#include <QApplication>
#include <QGLWidget>

int main(int argc, char** argv) {
  // Create a Qt application
  QApplication app( argc, argv );
  // create a new OpenGL Qt window
  QGLWidget* gl = new QGLWidget(0);
  app.setMainWidget( gl );
  gl->show();
  return app.exec();
}