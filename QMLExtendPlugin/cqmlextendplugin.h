#ifndef CQMLEXTENDPLUGIN_H
#define CQMLEXTENDPLUGIN_H

#include <QQuickItem>

class CQMLExtendPlugin : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(CQMLExtendPlugin)

public:
    CQMLExtendPlugin(QQuickItem *parent = 0);
    ~CQMLExtendPlugin();
};

#endif // CQMLEXTENDPLUGIN_H
