// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#include "edViewText.h"

#include <dtkCore/dtkAbstractViewFactory.h>
#include <dtkCore/dtkAbstractData.h>

// /////////////////////////////////////////////////////////////////
// edViewTextPrivate
// /////////////////////////////////////////////////////////////////

class edViewTextPrivate
{
public:
    QString text;
};

// /////////////////////////////////////////////////////////////////
// edViewText
// /////////////////////////////////////////////////////////////////

edViewText::edViewText(void) : dtkAbstractView(), d(new edViewTextPrivate)
{

}

edViewText::~edViewText(void)
{

}

bool edViewText::registered(void)
{
    return dtkAbstractViewFactory::instance()->registerViewType("edViewText", createEdViewText);
}

QString edViewText::description(void) const
{
    return "edViewText";
}

void edViewText::setData(dtkAbstractData *data)
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";

    QString* pText = static_cast<QString*>( data->data() );
    if (pText) {
        d->text = *pText;
    }
}


QWidget *edViewText::widget(void)
{
    QLabel* newLabel = new QLabel();
    newLabel->setText( d->text );
    return newLabel;
}
// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractView *createEdViewText(void)
{
    return new edViewText;
}
