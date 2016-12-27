#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "interaction.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    CInteraction* pInteraction=new CInteraction(nullptr);

    engine.rootContext()->setContextProperty("interaction", pInteraction);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    QObject* root = engine.rootObjects().first();


    //c++ 函数连接 qml信号
    QObject* quitButton = root->findChild<QObject*>("quitButton");
    if (quitButton)
    {
        QObject::connect(quitButton, SIGNAL(clicked()), &app, SLOT(quit()));
    }


    QObject* textLabel = root->findChild<QObject*>("objNameL4");
    if (textLabel)
    {
        //c++ 直接调用qml函数
        QMetaObject::invokeMethod(textLabel, "setL4text");

    }


    return app.exec();
}
