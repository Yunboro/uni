
#ifndef KOMPONENTENLIST_H
#define KOMPONENTENLIST_H

#include "komponente.h"
#include "ikomponente.h"

#include <iostream>

struct IKomponentenElement
{
    IKomponente* k;
    IKomponentenElement* before;
    IKomponentenElement* next;
};

struct KomponentenElement
{
    Komponente* k;
    KomponentenElement* before;
    KomponentenElement* next;
};

class KomponentenList
{
    private:
        int counter;  //Anzahl der gespeicherten Elemente
        KomponentenElement* first;
        KomponentenElement* getElement(int pos) const{
            KomponentenElement* erg = nullptr;      //Initialisierung
            if (0 <= pos && pos < counter){         // Check ob pos einen erlaubten Wert besitzt
              erg = first;                          //Vorerst mit first belegen
              for(int i = 0; i < pos; ++i) {        //Bis zu pos wandern
                  erg = erg->next; // erg = (*erg).next
              }
             }
             return erg;

        }


    public:
        //Beide Attribute mit 0 initialisieren
        //Da first ein Zeiger ist nullptr verwenden
        KomponentenList() : counter(0), first(nullptr) {}



        int size() const {
            return counter;
        }

        Komponente const* at(int pos) const {
            Komponente* erg = nullptr;
            KomponentenElement* element = getElement(pos);
            if(element) {               //Check ob Komponenten Element gefunden
                erg = element->k;
            }
            return erg;
        }

        int erase(int pos) {
            int erg = -1;

            if (counter > 0 && pos >= 0 && pos < counter) {
                KomponentenElement* element = getElement(pos);
                if(element) {
                    //erg = pos;

                    KomponentenElement* vor = element->before;  // Vorgänger Komponenten Element
                    KomponentenElement* nach = element->next;   // Nachgänger Komponenten Element

                    // 1) im Tafelbild
                    if (nach != nullptr) {
                    nach->before = vor;
                    }

                    // 2) im Tafelbild
                    if (vor != nullptr) {
                    vor->next = nach;
                    }
                    // Falls element das erste Element war:
                    if (element == first) {
                        first = nach;
                        if (first != nullptr) {
                            first->before = nullptr; // weil kein Vorgänger mehr da ist
                        }

                     }
                }
                delete element;
                --counter;
                erg = pos;
            }

        return erg;
        }





        void push_back(Komponente* k) {
            if (k != nullptr) {

                KomponentenElement* neu = new KomponentenElement;   // Neues Komponenten Element anlegen
                // Initialisierung des neuen Elements
                neu->k = k;
                neu->before = nullptr;
                neu->next = nullptr;

                // an letzte Stelle schieben
                if(first == nullptr) {
                  first = neu;
                }else {
                    int pos = counter-1;
                    KomponentenElement* letztes = getElement(pos);

                    if (letztes != nullptr) {
                        letztes->next = neu;
                        neu->before = letztes;
                    }

                }
                ++counter;

            }
        }


        KomponentenElement* begin() const{
            return first;
        }

        KomponentenElement* end() const{
            return nullptr;
        }

        ~KomponentenList() {

            KomponentenElement* tmp;
            while (first != nullptr) {
              tmp = first->next;
              delete first;
              first = tmp;
            }
            counter = 0;

          }



//  ----- ALTERNATIV -------
//        void push_back(Komponente* k) {

//            KomponentenElement* neu = new KomponentenElement;   // Neues Komponenten Element anlegen
//            // Initialisierung des neuen Elements
//            neu->k = k;
//            neu->before = nullptr;
//            neu->next = nullptr;

//        if(first == nullptr) {
//          first = neu;
//        } else {

//          KomponentenElement* letztes = first;
//          while (letztes->next != nullptr){
//            letztes = letztes->next;
//          }
//          // 1) im Tafelbild
//          neu->before = letztes;

//          // 2) im Tafelbild
//          letztes->next = neu;
//        }
//        ++counter;
//      }


};

inline std::ostream& operator<<(std::ostream& os, const KomponentenList& kl)
{
    os << "Ausgabe der Liste" << std::endl;
    int ksize = kl.size();

    for (int i = 0; i < ksize; i++)
    {
        const Komponente* k = kl.at(i);

        if (k)
        {
            k->output(os);
            os << std::endl;
        }
    }

    return os;
}



#endif // KOMPONENTENLIST_H
