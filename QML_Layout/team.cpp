#include "team.h"

Team::Team(QObject *parent)
    : QObject{parent}
{
    _names = QList<QString>() <<
    "Franck FURIC" <<
    "Jean-Marie REMOLEUR" <<
    "François WIBAUX" <<
    "Eric LEPORT" <<
    "Quatre" <<
    "Cinq" <<
    "Six" <<
    "Sept" <<
    "Huit" <<
    "Neuf";

    // _names = QList<QString>() <<
    // "0" <<
    // "1" <<
    // "2" <<
    // "3" <<
    // "4" <<
    // "5" <<
    // "6" <<
    // "7" <<
    // "8" <<
    // "9";

    //qDebug() << "init List Names " << _names;
}

Team::~Team()
{
    //qDebug() << "T is deleted";
}

QString Team::getRndTeamNames()
{
    _numList.clear();
    _rndNames.clear();
    for(int i=0; i<_names.size() ;i++)
    {
        _numList.append(i);
    }

    for(int i=_numList.size(); i>0 ;--i)
    {
        // qDebug() << "Lenght of _numList " << _numList.size();
        int rnd = QRandomGenerator::global()->bounded(_numList.length());
        // qDebug() << "Rnd choice => " << rnd << "Index of rnd " << _numList.at(rnd);
        // qDebug() << "_numList " << _numList;
        _rndNames.append(_names.at(_numList.at(rnd)));
        _numList.removeAt(rnd);
        // qDebug() << "_numList " << _numList;
        // qDebug() << "_rndNames " << _rndNames;
        // qDebug() << "=====================================================";
    }

    return _rndNames.join(", ");
}
