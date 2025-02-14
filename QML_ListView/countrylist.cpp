#include "countrylist.h"

CountryList::CountryList(
    QObject *parent)
    : QObject{parent}
{
    mItems.append({true, "France", "FR", QImage("/flag-icons/1.jpg") });
    mItems.append({false, "Bretagne", "BZ", QImage("/flag-icons/fr.svg") });
}

QList<CountryItem> CountryList::items() const
{
    return mItems;
}

bool CountryList::setItemAt(int index, const CountryItem &item)
{
    if(index < 0 || index >= mItems.count())
        return false;

    const CountryItem &oldItem = mItems.at(index);
    if(item.name == oldItem.name && item.flag == oldItem.flag)
        return false;

    mItems[index] = item;
    return true;
}

void CountryList::appendItem()
{
    emit preItemAppend();
    CountryItem it;
    it.slelected = false;
    mItems.append(it);
    emit postItemAppend();
}

void CountryList::removeCompletedItem()
{
    for (int i = 0; i < mItems.size(); ++i) {
        if(mItems.at(i).slelected){
            emit preRemoveItem(i);
            mItems.removeAt(i);
            emit postRemovedItem();
        }
    }
}
