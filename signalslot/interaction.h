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
    //想在qml被调用，必须被Q_INVOKABLE处理
    Q_INVOKABLE void  test();
};

#endif // CINTERACTION_H
