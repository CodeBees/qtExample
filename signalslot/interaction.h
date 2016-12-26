#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>

class CInteraction : public QObject
{
    Q_OBJECT


public:
    explicit CInteraction(QObject *parent = 0);

signals:
    void connectcppsignal(QString strMsg);

public slots:

public:

    Q_INVOKABLE void  test();
};

#endif // CINTERACTION_H
