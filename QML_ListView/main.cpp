#include <CountryList.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "listcountrymodel.h"

int main(
    int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ListCountryModel>("ListCountry", 1, 0, "ListCountryModel");

    CountryList myCountryList;
    myCountryList.append(CountryItem({false, "Bretagne", "BZ", "/flag-icons/aw.svg"}));
    myCountryList.append(false, "Coco", "co", "/flag-icons/as.svg");

    ListCountryModel monModel;
    monModel.setList(&myCountryList);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("countryModel", &monModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QML_ListView", "Main");

    return app.exec();
}
