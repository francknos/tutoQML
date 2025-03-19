#include "listcountrymodel.h"
#include "countrylist.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<ListCountryModel>("ListCountry", 1, 0, "ListCountryModel");

    CountryList myCountryList;
    myCountryList.append(CountryItem({false, "Bretagne", "BZ", "/flag-icons/aw.svg"}));
    myCountryList.append(false, "Coco", "co", "/flag-icons/as.svg");

    ListCountryModel monModel;
    monModel.setList(&myCountryList);


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("countryModel", &monModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
