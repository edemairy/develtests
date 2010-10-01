#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMultiMap>
#include <QRectF>
#include <cmath>

class NodeItem: public QGraphicsItem {
private:
    int x;
    int y;
    QString name;
public:
    static const int Radius;
    static const int PenWidth;

    NodeItem( int i_x, int i_y, QString i_name ): x(i_x), y(i_y), name(i_name){}
    QRectF boundingRect() const
     {
         return QRectF( x - Radius/2 -  PenWidth , y - Radius /2 - PenWidth , x + Radius/2 + PenWidth , y + Radius /2 + PenWidth );
     }

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget)
     {
        // painter->drawEllipse( x - Radius/2 , y - Radius /2 , Radius, Radius );
         painter->setPen( QPen( Qt::green ) );
         painter->setBackgroundMode( Qt::OpaqueMode );
         painter->setBrush( QBrush( Qt::green, Qt::RadialGradientPattern ) );
         painter->setBackground( QBrush( Qt::green, Qt::RadialGradientPattern ) );

         painter->drawEllipse( x - Radius/2 , y - Radius /2 , Radius, Radius );
         painter->drawText( x , y , name);
     }
};

const int NodeItem::PenWidth = 10;
const int NodeItem::Radius = 20;

class Graph {
private:
    int nbNodes;
    QMultiMap<int,int> matrix;
public:
    Graph( int i_nbNodes ): nbNodes( i_nbNodes ) {
    }
    void insert( int i, int j) {
        matrix.insert( i, j );
    }
    void draw( QGraphicsScene& scene ) {
        int posX = 0;
        int posY = 0;
        for ( int i = 0; i < nbNodes; ++i ) {
            posX = 50 + 50*cos( i*2*M_PI / nbNodes );
            posY = 50 + 50*sin( i*2*M_PI / nbNodes );

            scene.addItem( new NodeItem( posX, posY, QString("%1").arg(i) ));\
        }
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QGraphicsScene* gScene = new QGraphicsScene;
    QGraphicsView* gView = new QGraphicsView(gScene);
    Graph graph(10);
    graph.draw( *gScene );
    w.setCentralWidget( gView );
    w.show();
    return a.exec();
}
