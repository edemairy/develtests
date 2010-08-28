#include <QObject>
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

