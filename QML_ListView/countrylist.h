#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include <QImage>
#include <QObject>
#include <QVector>

struct CountryItem
{
    bool slelected;
    QString name;
    QString shortName;
    QImage flag;
};

class CountryList : public QObject
{
    Q_OBJECT
public:
    explicit CountryList(QObject *parent = nullptr);

    QList<CountryItem> items() const;

    bool setItemAt(int index, const CountryItem &item);


signals:
    void preItemAppend();
    void postItemAppend();

    void preRemoveItem(int index);
    void postRemovedItem();

public slots:
    void appendItem();
    void removeCompletedItem();

private:
    QList<CountryItem> mItems;
};

#endif // COUNTRYLIST_H
