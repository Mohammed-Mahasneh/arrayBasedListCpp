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
    const arrayBasedList<elemType> &operator=(const arrayBasedList<elemType> &);
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
    void fillList();
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