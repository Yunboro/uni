#include "delist.h"

    int counter;  //Anzahl der gespeicherten Elemente
    IKomponentenElement* first;

    IKomponentenElement* DeList::getElement(Iterator it) const {
        IKomponentenElement* erg = nullptr;

        if (first != nullptr) {
            erg = first;

            while (erg != nullptr) {
                if (*it == erg->k) {
                    break;
                }

                erg = erg->next;
            }
        }

        return erg;
    }

    DeList::DeList() : counter(0), first(nullptr) {}

    int DeList::size() const {
        return counter;
    }

    Iterator DeList::begin() const {
        return Iterator(first);
    }

    Iterator DeList::end() const {
        return Iterator(nullptr);
    }

    Iterator DeList::erase(Iterator pos) {
        Iterator erg;
        IKomponentenElement* element = getElement(pos);

        if (element != nullptr) {
            erg = ++pos;

            IKomponentenElement* vor = element->before;
            IKomponentenElement* nach = element->next;

            if (nach != nullptr) {
                nach->before = vor;
            }

            if (vor != nullptr) {
                vor->next = nach;
            }

            if (element == first) {
                first = nach;
                if (first != nullptr) {
                    first->before = nullptr;
                }
            }

            delete element;
            --counter;
        }

        return erg;
    }

    void DeList::push_back(IKomponente* komp) {
        IKomponentenElement* element_to_add = new IKomponentenElement{komp, nullptr, nullptr};
        Iterator pos = begin();

        if (pos == end()) {
            first = element_to_add;
        } else {
            IKomponentenElement* current = first;

            while (++pos != end()) {
                current = current->next;
            }

            current->next = element_to_add;
            element_to_add->before = current;
        }

        ++counter;
    }

    void DeList::clear() {
        IKomponentenElement* e = first;

        while (e) {
            IKomponentenElement* e_neu = e->next;
            delete e;
            e = e_neu;
        }

        counter = 0;
    }

    DeList::DeList(DeList const& rhs) : counter{0}, first{nullptr} {
        Iterator it = rhs.begin();

        while (it != rhs.end()) {
            push_back(*it);
            ++it;
        }
    }

    DeList& DeList::operator=(DeList const& rhs) {
        if (this != &rhs) {
            clear();

            Iterator it = rhs.begin();

            while (it != rhs.end()) {
                push_back(*it);
                ++it;
            }
        }
        return *this;
    }

    DeList::~DeList() {
        clear();
    }

