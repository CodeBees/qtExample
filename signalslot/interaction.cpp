#include "interaction.h"

CInteraction::CInteraction(QObject *parent) : QObject(parent)
{

}

void CInteraction::test()
{
    QString strMsg("cpp slot");
    //发射信号
    emit connectcppsignal(strMsg);

}
