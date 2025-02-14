#include <CountryList.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "countrylist.h"
#include "listcountrymodel.h"

int main(
    int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ListCountryModel>("ListCountry", 1, 0, "ListCountryModel");

    //ListCountryModel item;
    CountryList myCountryList;

    QQmlApplicationEngine engine;



    QList<QQmlContext::PropertyPair> properties;
    properties.append(QQmlContext::PropertyPair{"plop", QVariant::fromValue(&myCountryList)});
    properties.append(QQmlContext::PropertyPair{"papa", QVariant::fromValue(&myCountryList)});


    engine.rootContext()->setContextProperty("countryList", &myCountryList);
    engine.rootContext()->setContextProperties(properties);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QML_ListView", "Main");

    return app.exec();
}
