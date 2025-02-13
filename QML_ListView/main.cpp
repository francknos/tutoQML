#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "listcountrymodel.h"

int main(
    int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ListCountryModel>("ListCountry", 1, 0, "ListCountryModel");

    //ListCountryModel item;

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QML_ListView", "Main");

    return app.exec();
}
