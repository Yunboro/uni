#include "iterator.h"


    Iterator::Iterator(IKomponentenElement* begin)
        : curr{begin}
    {}


    Iterator& Iterator::operator ++() {
        if (curr != nullptr) {
            curr = curr->next;
        }
        return *this;
    }

    bool Iterator::operator ==(Iterator const& it) {
        return this->curr == it.curr;
    }

    bool Iterator::operator !=(Iterator const& it) {
        return this->curr != it.curr;
    }

    IKomponente* Iterator::operator *() {
        return curr->k;
    }


    Iterator::~Iterator() {};
