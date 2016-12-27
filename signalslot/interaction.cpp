#include "interaction.h"
#include <qdebug.h>
#include <QTime>
#include <iostream>

void outPutInfo()
{
    qDebug()<<"normat function";
}



CInteraction::CInteraction(QObject *parent) : QObject(parent)
{
    value_=0;

    //连接c++ 信号与槽
    //QObject::connect(this,SIGNAL(valueChanged(int)),this,SLOT(setValue(int))); //qt4 语法
    QObject::connect(this,&CInteraction::valueChanged,this,&CInteraction::setValue); //qt5 新语法

    //信号连接普通函数
    QObject::connect(this,&CInteraction::valueChanged,outPutInfo);
    //信号链接c++11 lambda函数
    // QObject::connect(this,&CInteraction::valueChanged,[=](int value){  qDebug()<<"lambda called, value:"<<value<<"\n"; });
    QObject::connect(this,&CInteraction::valueChanged,[=,this](){  qDebug()<<"lambda called, value:"<<this->value_<<"\n"; });
}

void CInteraction::test()
{
    QString strMsg("cpp slot");
    //发射信号
    emit connectcppsignal(strMsg);


    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    int nRand = qrand();

    emit valueChanged(nRand);

}


void CInteraction::setValue(int value)
{

    value_=value;

    qDebug()<<"value:"<<value;

}
