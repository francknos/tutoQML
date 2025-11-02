#ifndef TEAM_H
#define TEAM_H

#include <QObject>
#include <QQmlEngine>
#include <QRandomGenerator>

class Team : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Team(QObject *parent = nullptr);
    ~Team();
    Q_INVOKABLE QString getRndTeamNames();

private:
    QList<QString> _names;
    QList<int> _numList;
    QList<QString> _rndNames;

};

#endif // TEAM_H
