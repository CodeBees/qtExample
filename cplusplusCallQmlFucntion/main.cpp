#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects().first();


    QObject* pctrlobj = root->findChild<QObject*>("TextExtend");
    if (pctrlobj)
    {

        QVariant returnedValue;
        QVariant msg = "message sended from C++";
        QMetaObject::invokeMethod(pctrlobj, "setTextString", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, msg));


    }

    return app.exec();
}
