// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#include "edProcessTextGenerator.h"
#include "edProcessTextGeneratorPlugin.h"

#include <dtkCore/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// edProcessTextGeneratorPluginPrivate
// /////////////////////////////////////////////////////////////////

class edProcessTextGeneratorPluginPrivate 
{
public:
    // Class variables go here.
};

// /////////////////////////////////////////////////////////////////
// edProcessTextGeneratorPlugin
// /////////////////////////////////////////////////////////////////

edProcessTextGeneratorPlugin::edProcessTextGeneratorPlugin(QObject *parent) : dtkPlugin(parent), d(new edProcessTextGeneratorPluginPrivate)
{

}

edProcessTextGeneratorPlugin::~edProcessTextGeneratorPlugin(void)
{
    delete d;

    d = NULL;
}

bool edProcessTextGeneratorPlugin::initialize(void)
{
    if(!edProcessTextGenerator::registered())
	dtkWarning() << "Unable to register edProcessTextGenerator type";

    return true;
}

bool edProcessTextGeneratorPlugin::uninitialize(void)
{
    return true;
}

QString edProcessTextGeneratorPlugin::name(void) const
{
    return "edProcessTextGeneratorPlugin";
}

QString edProcessTextGeneratorPlugin::description(void) const
{
    return "";
}

QStringList edProcessTextGeneratorPlugin::tags(void) const
{
    return QStringList();
}

QStringList edProcessTextGeneratorPlugin::types(void) const
{
    return QStringList() << "edProcessTextGenerator";
}

Q_EXPORT_PLUGIN2(edProcessTextGeneratorPlugin, edProcessTextGeneratorPlugin)
