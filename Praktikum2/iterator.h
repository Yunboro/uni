#ifndef ITERATOR_H
#define ITERATOR_H
#include "ikomponente.h"
#include "komponentenlist.h"

class Iterator {
private:
    IKomponentenElement* curr;

public:
    explicit Iterator(IKomponentenElement* begin = nullptr);


    Iterator& operator ++();


    bool operator ==(Iterator const& it);

    bool operator !=(Iterator const& it);

    IKomponente* operator*();


    ~Iterator();
};

#endif // ITERATOR_H
