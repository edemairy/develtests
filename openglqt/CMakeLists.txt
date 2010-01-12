project(openglqt)
find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL 1)
include(${QT_USE_FILE})

add_executable(openQGLWidget 
  openQGLWidget.cpp
)
target_link_libraries(openQGLWidget ${QT_LIBRARIES})


QT4_WRAP_CPP( GFILES   DrawTriangleGLWidget.h )
add_executable(drawTriangleQGLWidget
  drawTriangleQGLWidget.cpp
  DrawTriangleGLWidget.h
  ${GFILES}
)
target_link_libraries(drawTriangleQGLWidget ${QT_LIBRARIES})

QT4_WRAP_CPP( GFILES2   SpinningCubeQGLWidget.h )
add_executable(SpinningCubeQGLWidget
  spinningCubeQGLWidget.cpp
  SpinningCubeQGLWidget.h
  ${GFILES2}
)
target_link_libraries(SpinningCubeQGLWidget ${QT_LIBRARIES} glut)
