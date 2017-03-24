#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "classmate.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    ClassMateTableModel* pptv=new ClassMateTableModel;

    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("paremTableViewModel", pptv);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    return app.exec();
}
