#include "interaction.h"

CInteraction::CInteraction(QObject *parent) : QObject(parent)
{

}

void CInteraction::test()
{
    QString strMsg("cpp slot");

    emit connectcppsignal(strMsg);

}
