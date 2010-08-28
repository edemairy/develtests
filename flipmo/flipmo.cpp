#include <QtGui>

class FlipWidget : public QGraphicsWidget
{
    Q_OBJECT
public:
    FlipWidget(QGraphicsItem *parent = 0);
Q_SIGNALS:
    void flipRequest(); // private
protected:
    void resizeEvent(QGraphicsSceneResizeEvent *event);
private slots:
    void togglePage();
private:
    QStackedWidget *m_stack;
};

FlipWidget::FlipWidget(QGraphicsItem *parent)
    : QGraphicsWidget(parent)
{
    // The front.
    QWidget *front = new QWidget();
    QPushButton *toBackButton = new QPushButton("To Back");
    QObject::connect(toBackButton, SIGNAL(clicked()), this, SIGNAL(flipRequest()));
    toBackButton->setStyleSheet("background: pink");
    {
        QVBoxLayout *vbox = new QVBoxLayout(front);
        vbox->addWidget(toBackButton);
    }

    // The back.
    QWidget *back = new QWidget();
    QPushButton *toFrontButton = new QPushButton("To Front");
    QObject::connect(toFrontButton, SIGNAL(clicked()), this, SIGNAL(flipRequest()));
    toFrontButton->setStyleSheet("background: yellow");
    {
        QVBoxLayout *vbox = new QVBoxLayout(back);
        vbox->addWidget(toFrontButton);
    }

    // The stacked widget.
    m_stack = new QStackedWidget();
    m_stack->addWidget(front);
    m_stack->addWidget(back);

    QGraphicsRotation* rotation = new QGraphicsRotation();
    rotation->setAxis( QVector3D( 1, 1, 1) );
    QList<QGraphicsTransform *> transformations;
    transformations << rotation;
    setTransformations( transformations );

    QGraphicsProxyWidget *stackProxy = new QGraphicsProxyWidget();
    stackProxy->setWidget(m_stack);
    QGraphicsLinearLayout *vbox = new QGraphicsLinearLayout(this);
    vbox->addItem(stackProxy);

    rotation->setOrigin( QVector3D( front->width()/4 ,front->height()/4,0) );
    // The states and animations.
    QStateMachine *machine = new QStateMachine(this);
    QState *s0 = new QState(machine);
    s0->assignProperty(rotation, "angle", 0);

    QState *s1 = new QState(machine);
    s1->assignProperty(rotation, "angle", 90);

    QAbstractTransition *t1 = s0->addTransition(this, SIGNAL(flipRequest()), s1);
    QPropertyAnimation *yRotationAnim = new QPropertyAnimation(rotation, "angle");
    yRotationAnim->setDuration(250);
    t1->addAnimation(yRotationAnim);

    QState *s2 = new QState(machine);
    QObject::connect(s2, SIGNAL(entered()), this, SLOT(togglePage()));
    s2->assignProperty(rotation, "angle", -90);
    s1->addTransition(s1, SIGNAL(propertiesAssigned()), s2);

    QAbstractTransition *t2 = s2->addTransition(s0);
    t2->addAnimation(yRotationAnim);

    machine->setInitialState(s0);
    machine->start();
}

void FlipWidget::togglePage()
{
    m_stack->setCurrentIndex(m_stack->currentIndex() ^ 1);
}

void FlipWidget::resizeEvent(QGraphicsSceneResizeEvent *event)
{
    QSizeF siz = event->newSize();
    QPointF pt = QPointF(siz.width() / 2, siz.height() / 2);
    setTransformOriginPoint(pt);
}

class Window : public QWidget
{
public:
    Window(QWidget *parent = 0)
        : QWidget(parent) {
        QGraphicsScene *scene = new QGraphicsScene(this);
        QGraphicsWidget *widget = new QGraphicsWidget();
        QGraphicsGridLayout *grid = new QGraphicsGridLayout(widget);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j)
                grid->addItem(new FlipWidget(), i, j);
        }
        scene->addItem(widget);
        QGraphicsView *view = new QGraphicsView(scene);
        QVBoxLayout *vbox = new QVBoxLayout(this);
        vbox->addWidget(view);
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Window win;
    win.resize(640, 640);
    win.show();
    return app.exec();
}

#include "moc_flipmo.cxx"
