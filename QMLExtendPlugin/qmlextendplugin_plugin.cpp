#include "qmlextendplugin_plugin.h"
#include "cqmlextendplugin.h"

#include <qqml.h>

void QMLExtendPluginPlugin::registerTypes(const char *uri)
{
    // @uri com.ink.qmlcomponents
    qmlRegisterType<CQMLExtendPlugin>(uri, 1, 0, "CQMLExtendPlugin"); //import com.ink.qmlcomponents 1.0

}

