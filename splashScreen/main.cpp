#include <QApplication>
#include <QMainWindow>
#include <QPixmap>
#include <QSplashScreen>
int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
//     QPixmap pixmap(":/splash.png");
     QPixmap pixmap("../hello_world.png");
     QSplashScreen splash(pixmap);
     splash.show();
     app.processEvents();
     QMainWindow window;
     window.show();
    
     sleep(5);
     splash.showMessage("Loaded modules");
     qApp->processEvents();

     sleep(5);
     // Establishing connections
     splash.showMessage("Established connections");
     qApp->processEvents();
     
     sleep(5);
     splash.finish(&window);
     return app.exec();
 }
