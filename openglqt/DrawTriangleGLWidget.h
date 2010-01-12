#include <QGLWidget>
#include <QWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QObject>
#include <QTimer>

class DrawTriangleGLWidget : public QGLWidget 
{
   Q_OBJECT
  public:
      DrawTriangleGLWidget( QWidget* parent = 0):
	QGLWidget(parent)
	{
	}
  protected:
      //Initialize OpenGL. This is called automaticallly by Qt
      virtual void initializeGL()
      {
	// Initialization code must be placed here
	
	// glClear() clears to white background
	glClearColor(  1.0, 1.0, 1.0, 0.0 );
	
	// Dithering is usually not needed
	glDisable( GL_DITHER );
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
	// Insert code to render the scene here
	
	// Reset the modelview matrix
	glLoadIdentity();
	
	// Clear the color buffer (contents of the window) and the
	// depth buffer (z-values)
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	// Draw the following object in red
	glColor3f( 1.0, 0.0, 0.0 );
	
	// Draw a triangle
	glBegin( GL_POLYGON );
	  glVertex3f( 0.0, 0.0, -2.0 );
	  glVertex3f( 0.0, 1.0, -2.0 );
	  glVertex3f( 1.0, 1.0, -2.0 );
        glEnd();
      }
   };
	
