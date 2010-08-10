#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <cmath>

QVector<QPoint> computeHexagonVertices( int x, int y, int r, bool isHorizontal = true ) {
    QVector<QPoint> result;
    result.append( QPoint( x - r * cos( 2*M_PI * (60./360) ), y - r * sin( 2*M_PI * (60./360) ) ) );
    result.append( QPoint( x + r * cos( 2*M_PI * (60./360) ), y - r * sin( 2*M_PI * (60./360) ) ) );
    result.append( QPoint( x + r , y ) );
    result.append( QPoint( x + r * cos( 2*M_PI * (60./360) ), y + r * sin( 2*M_PI * (60./360) ) ) );
    result.append( QPoint( x - r * cos( 2*M_PI * (60./360) ), y + r * sin( 2*M_PI * (60./360) ) ) );
    result.append( QPoint( x - r , y ) );
    return result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout* layout = new QHBoxLayout(ui->centralWidget);
    QLabel* label = new QLabel( "Hello World" );
    QGraphicsScene* scene = new QGraphicsScene();
    scene->addLine( 15,15,  -5,35);
    scene->addLine( 15,15, 35,35);
    scene->addEllipse(10, 10,10,10);
    scene->addEllipse(-10,30,10,10);
    scene->addEllipse(30, 30,10,10);
    scene->addPolygon( QPolygon( computeHexagonVertices( 0,  50,25 ) ) );
    scene->addPolygon( QPolygon( computeHexagonVertices( 50,  25,25 ) ) );
    scene->addPolygon( QPolygon( computeHexagonVertices( 75 ,50,25 ) ) );
    scene->addPolygon( QPolygon( computeHexagonVertices( 125,50,25 ) ) );
    scene->addPolygon( QPolygon( computeHexagonVertices( 200,50,25 ) ) );

    QGraphicsView* view = new QGraphicsView( scene );
    layout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
