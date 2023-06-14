#ifndef DELIST_H
#define DELIST_H
#include "iterator.h"
#include "komponentenlist.h"
class DeList {

private:
    int counter;  //Anzahl der gespeicherten Elemente
    IKomponentenElement* first;
    IKomponentenElement* getElement(Iterator it) const;
public:
    DeList();
    int size() const;
    Iterator begin() const;
    Iterator end() const;
    Iterator erase(Iterator pos);
    void push_back(IKomponente* komp);
    void clear();
    DeList(DeList const& rhs);
    DeList& operator=(DeList const& rhs);

    ~DeList();


};

#endif // DELIST_H
