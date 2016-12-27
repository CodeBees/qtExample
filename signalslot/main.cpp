#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickItem>
#include <QCursor>

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

   // modify the item's properties using QObject::setProperty() or QQmlProperty:

    QObject* textLabel1 = root->findChild<QObject*>("objNameL1");
    if (textLabel1)
    {
        //textLabel1->setProperty("color","yellow");
        QQmlProperty(textLabel1, "color").write("#888888");
    }

    //the ListView will have multiple children with the same objectName
    QObject* textLabel2 = root->findChild<QObject*>("objNameL2");
    if (textLabel2)
    {
        QQuickItem *item = qobject_cast<QQuickItem*>(textLabel2);
        QCursor cursor(Qt::WaitCursor);
        item->setCursor(cursor);
    }




    return app.exec();
}
