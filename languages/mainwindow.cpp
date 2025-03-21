#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMetaEnum>

MainWindow::MainWindow(
    QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//define country
    {
    listCountry.append("nl_NL");
    listCountry.append("en_GB");
    listCountry.append("et_ET");
    listCountry.append("fi_FI");
    listCountry.append("el_GR");
    listCountry.append("de_DE");
    listCountry.append("hu_HU");
    listCountry.append("it_IT");
    listCountry.append("lv_LV");
    listCountry.append("lt_LT");
    listCountry.append("no_NO");
    listCountry.append("pl_PL");
    listCountry.append("pt_PT");
    listCountry.append("ro_RO");
    listCountry.append("ru_RU");
    listCountry.append("zh_CN");
    listCountry.append("sl_SI");
    listCountry.append("es_ES");
    listCountry.append("sv_SE");
    listCountry.append("tr_TR");
    listCountry.append("pt_BR");
    listCountry.append("sk_SK");
    listCountry.append("sr_CS");
    listCountry.append("fr_FR");
    listCountry.append("hr_HR");
    listCountry.append("cs_CZ");
    listCountry.append("da_DK");
    }

    QString output;

    for (int i = 0; i < listCountry.count(); ++i) {
        output.append(QLocale::languageToString(QLocale(listCountry.at(i)).language()));output.append("\n");
        output.append(QLocale(listCountry.at(i)).nativeLanguageName());output.append("\n");
        output.append(QLocale(listCountry.at(i)).bcp47Name());output.append("_");
        output.append(QLocale(listCountry.at(i)).name().split('_').at(1));output.append("\n");
        output.append("==================================");output.append("\n");

        qDebug() << QLocale(listCountry.at(i)).language();
        qDebug() << QLocale::languageToString(QLocale(listCountry.at(i)).language());
        qDebug() << QLocale(listCountry.at(i)).nativeLanguageName();
        qDebug() << QLocale(listCountry.at(i)).bcp47Name();
        qDebug() << QLocale(listCountry.at(i)).name().split('_').at(1);
        qDebug()<< "==================================";
    }

    ui->plainTextEdit->document()->setPlainText(output);
}

MainWindow::~MainWindow()
{
    delete ui;
}

