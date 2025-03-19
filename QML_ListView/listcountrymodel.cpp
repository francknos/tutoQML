#include "CountryList.h"
#include "listcountrymodel.h"
#include <QImage>

ListCountryModel::ListCountryModel(QObject *parent)
    : QAbstractListModel(parent),
    mList(nullptr)
{
}

int ListCountryModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant ListCountryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const CountryItem item = mList->items().at(index.row());

    switch (role) {
    case DoneRole:
        return QVariant(item.slelected);
        break;
    case Country:
        return QVariant(item.name);
        break;
    case ShortName:
        return QVariant(item.shortName);
        break;
    case FlagRole:
        return QVariant(item.flag);
        break;
    default:
        break;
    }
    return QVariant();
}

bool ListCountryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags ListCountryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}


QHash<int, QByteArray> ListCountryModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[Country] = "country";
    names[ShortName] = "shortName";
    names[FlagRole] = "flag";
    return names;
}

CountryList *ListCountryModel::list() const
{
    return mList;
}

void ListCountryModel::setList(CountryList *newList)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);

    mList = newList;

    if(mList){
        connect(mList, &CountryList::preItemAppend, this, [=](){
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &CountryList::postItemAppend, this, [=](){
            endInsertRows();
        });
        connect(mList, &CountryList::preRemoveItem, this, [=](int idx){
            beginRemoveRows(QModelIndex(), idx, idx);
        });
        connect(mList, &CountryList::postRemovedItem, this, [=](){
            endRemoveRows();
        });
    }
    endResetModel();
}




