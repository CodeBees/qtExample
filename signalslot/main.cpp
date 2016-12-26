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


    pInteraction->test();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
