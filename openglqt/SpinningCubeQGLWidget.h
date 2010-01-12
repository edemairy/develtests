#include <QGLWidget>
#include <QWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <QObject>
#include <QTimer>

class DrawTriangleGLWidget : public QGLWidget 
{
   Q_OBJECT
  public:
      DrawTriangleGLWidget( QWidget* parent = 0):
	QGLWidget(parent)
	{
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
            timer->start();
	}
  protected:
      //Initialize OpenGL. This is called automaticallly by Qt
      virtual void initializeGL()
      {
	// Initialization code must be placed here
	
        // glClear() clears to black background
        glClearColor(  0.0, 0.0, 0.0, 0.0 );
        glEnable(GL_DEPTH_TEST);

	// Dithering is usually not needed
        //glDisable( GL_DITHER );
      }
      
      // Called automatically by Qt when the widget is resized.
      virtual void resizeGL( int width, int height )
      {
	// insert resizing code here
	
	// Make use of the whole widget
	glViewport( 0, 0, width, height );
	
	// Set up a 3D propjection matrix. See Projection settings of the 3D rendering section.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 60.0, ((GLdouble) width) / ((GLdouble)height), 0.0625, 512.0 );
	glMatrixMode( GL_MODELVIEW );
      }
      
      // Called automatically by Qt on paint events. Use the slot
      // updateGL() to call update the view manually.
      virtual void paintGL()
      {
 static float alpha = 0;
 static float accelx = 0.001;
 static float tx = 0;
  /* Clear the buffer, clear the matrix */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  /* A step backward, then spin the cube */
  glTranslatef(tx, 0, -10);
  glRotatef(30, 1, 0, 0);
  glRotatef(alpha, 0, 1, 0);

  /* We tell we want to draw quads */
  glBegin(GL_QUADS);

  /* Every four calls to glVertex, a quad is drawn */
  glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
  glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
  glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
  glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);

  glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);
  glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
  glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
  glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);

  glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
  glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
  glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
  glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);

  glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
  glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
  glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
  glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);

  glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
  glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
  glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);
  glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);

  glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
  glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
  glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
  glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);

  /* No more quads */
  glEnd();

  /* Rotate a bit more */
  alpha = alpha + 0.1;
  tx = tx + accelx;
  if ( tx >= 5 ) {
      accelx = -0.001;
  } else if ( tx <= -5 ) {
      accelx = 0.001;
  }
  /* End */
  glFlush();
  //glutSwapBuffers();

  /* Update again and again */
  //glutPostRedisplay();
      }
   };
	
