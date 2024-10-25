#include <iostream>
using namespace std;
template <class elemType>
class arrayBasedList
{
protected:
    int maxSize;
    int length;
    elemType *list;

public:
    arrayBasedList(int = 100);
    ~arrayBasedList();
    arrayBasedList(const arrayBasedList<elemType> &);
    const arrayBasedList<elemType> &operator=(const arrayBasedList<elemType> &);
    bool isEmpty() const;
    bool isFull() const;
    bool isItemEqual(int, const elemType &) const;
    int maxListSize() const;
    int listSize() const;
    void print() const;
    void insertAt(int, const elemType &);
    void insertEnd(const elemType &);
    void removeAt(int);
    void retrieveAt(int, const elemType &);
    void replaceAt(int, const elemType &);
    void clearList();
    int seqSearch(const elemType &) const;
    void insert(const elemType &);
    void remove(const elemType &);
};