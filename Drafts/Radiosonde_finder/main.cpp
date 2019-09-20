#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "BaloonDataContainer.h"

int main(int argc, char *argv[]) {

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    BaloonDataContainer radiosondesList;
    radiosondesList.addSondeId("R_12345678");
    radiosondesList.addSondeId("R_87654321");
    radiosondesList.addSondeId("R_87654000");
    radiosondesList.addSondeId("R_00654321");
    radiosondesList.addSondeId("R_11654321");
    radiosondesList.addSondeId("R_55678798");
    radiosondesList.addSondeId("R_46545101");
    radiosondesList.addSondeId("R_11654123");
    radiosondesList.addSondeId("R_11455780");

    const QUrl url(QStringLiteral("qrc:/UI/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("radiosondesList", &radiosondesList);
    engine.load(url);

    return app.exec();
}
