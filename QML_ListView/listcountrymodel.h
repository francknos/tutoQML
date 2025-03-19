#ifndef LISTCOUNTRYMODEL_H
#define LISTCOUNTRYMODEL_H

#include <QAbstractListModel>

class CountryList;

class ListCountryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(CountryList *listCountry READ list WRITE setList NOTIFY countryListChanged)

public:
    explicit ListCountryModel(QObject *parent = nullptr);

    enum {
        DoneRole = Qt::UserRole,
        Country,
        ShortName,
        FlagRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    CountryList *list() const;
    void setList(CountryList *newList);

signals:
    void countryListChanged();

private:
    CountryList *mList;

};

#endif // LISTCOUNTRYMODEL_H
