#include <iostream>
#include <cassert>
using namespace std;
template <class elemType>
class arrayBasedList
{
private:
    bool isLessOrEqualThanZero(int) const;
    bool isNegative(int) const;
    bool isZero(int) const;

protected:
    int maxSize;
    int length;
    elemType *list;

public:
    arrayBasedList(int = 100);
    ~arrayBasedList();
    arrayBasedList(const arrayBasedList<elemType> &);
    bool isItemEqual(int, const elemType &) const;
    bool isEmpty() const;
    bool isFull() const;
    int maxListSize() const;
    int listSize() const;
    int seqSearch(const elemType &) const;
    void print() const;
    void insertAt(int, const elemType &);
    void insertEnd(const elemType &);
    void removeAt(int);
    void retrieveAt(int, const elemType &);
    void replaceAt(int, const elemType &);
    void clearList();
    void insert(const elemType &);
    void remove(const elemType &);
};
template <class elemType>
bool arrayBasedList<elemType>::isNegative(int n) const
{
    if (n < 0)
        return true;
    return false;
}
template <class elemType>
bool arrayBasedList<elemType>::isZero(int n) const
{
    if (n == 0)
        return true;
    return false;
}
template <class elemType>
bool arrayBasedList<elemType>::isLessOrEqualThanZero(int n) const
{
    if (isZero(n) || isNegative(n))
        return true;
    return false;
}
template <class elemType>
arrayBasedList<elemType>::arrayBasedList(int size)
{
    if (isLessOrEqualThanZero(size))
        cerr << "maxSize cannot be zero or negative" << endl;
    else
    {
        maxSize = size;
        length = 0;
        list = new elemType[maxSize];
        assert(list != NULL);
    }
}
template <class elemType>
arrayBasedList<elemType>::~arrayBasedList()
{
    delete[] list;
}
template <class elemType>
bool arrayBasedList<elemType>::isEmpty() const
{
    return (length == 0);
}
template <class elemType>
bool arrayBasedList<elemType>::isFull() const
{
    return (length == maxSize);
}
template <class elemType>
int arrayBasedList<elemType>::maxListSize() const
{
    return maxSize;
}
template <class elemType>
int arrayBasedList<elemType>::listSize() const
{
    return length;
}
template <class elemType>
bool arrayBasedList<elemType>::isItemEqual(int loc, const elemType &item) const
{
    if (isLessOrEqualThanZero(loc) || loc >= length)
    {
        if (list[loc] == item)
            return true;
    }
    else
        cerr << "Invalid location" << endl;
}
template <class elemType>
arrayBasedList<elemType>::arrayBasedList(const arrayBasedList<elemType> &otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);
    for (int i = 0; i < length; i++)
    {
        list[i] = otherList.list[i];
    }
}
template <class elemType>
int arrayBasedList<elemType>::seqSearch(const elemType &item) const
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] == item)
            return i;
    }
    return -1;
}
template <class elemType>
void arrayBasedList<elemType>::print() const
{
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
template <class elemType>
void arrayBasedList<elemType>::insertAt(int loc, const elemType &item)
{
    if (isLessOrEqualThanZero(loc) || loc >length)
        cerr << "Invalid location" << endl;
    else if (isFull())
        cerr << "Cannot insert into a full list" << endl;
    else
        list[loc] = item;
    for (int i = length; i > loc; i--)
    {
        list[i] = list[i - 1];
    }
    length++;
}
template <class elemType>
void arrayBasedList<elemType>::insertEnd(const elemType &item)
{
    if (isFull())
        cerr << "Cannot insert into a full list" << endl;
    else
    {
        list[length] = item;
        length++;
    }
}
template <class elemType>
void arrayBasedList<elemType>::removeAt(int loc)
{
    if (isLessOrEqualThanZero(loc) || loc >= length)
        cerr << "Invalid location";
    else if (isEmpty())
        cerr << "Cannot remove from an empty list" << endl;
    else
    {
        for (int i = loc; i < length - 1; i++)
        {
            list[i] = list[i + 1];
        }
        length--;
    }
}
template <class elemType>
void arrayBasedList<elemType>::retrieveAt(int loc, const elemType &item)
{
    if (loc > length || isLessOrEqualThanZero(loc))
        cerr << "Invalid location" << endl;
    else
        return list[loc];
}
template <class elemType>
void arrayBasedList<elemType>::replaceAt(int loc, const elemType &item)
{
    if (isLessOrEqualThanZero(loc) || loc >= length)
        cerr << "Invalid location" << endl;
    else
        list[loc] = item;
}
template <class elemType>
void arrayBasedList<elemType>::clearList()
{
    length = 0;
}
template <class elemType>
void arrayBasedList<elemType>::insert(const elemType &item)
{
    if (seqSearch(item) != -1)
        cerr << "Cannot insert duplicate items" << endl;
    else
        insertEnd(item);
}
template <class elemType>
void arrayBasedList<elemType>::remove(const elemType &item)
{
    removeAt(seqSearch(item));
}