#include "werkstueck.h"


Iterator Werkstueck::getNearest(const IKomponente* pk) const {
        // Iterator it, erg = komponenten.begin();      // ACHTUNG: so wird nur erg initialisiert!!
        Iterator it = komponenten.begin();
        Iterator erg = komponenten.begin();
        //std::cout << "Erg: "<< **erg << std::endl;
        double min = INFINITY;  // Min erstmal unendlich groß setzten
        while(it != komponenten.end()) {
            if((*it)->distance(pk) < min) {     // falls Distanz zur Iterator Komponente kleiner als bisheriges Minimum ist
                min = (*it)->distance(pk);      //speichere Wert falls kleiner als vorheriger Wert
                erg = it;               //Ergebnis Iterator neu setzten
            }
            ++it;
        }
        return erg;
    }


Werkstueck::Werkstueck(double xPos, double yPos, double h, double w)
        :   Komponente{xPos, yPos}, height{h}, width{w}, pathIsOptimized{false}
    {}

    double Werkstueck::getHeight() const{
        return height;
    }

    double Werkstueck::getWidth() const{
        return width;
    }

    void Werkstueck::add(IKomponente* k) {
        //std::cout << "add" << std::endl;
        //if (k != nullptr) {
        k->setParent(this);
        komponenten.push_back(k);
        pathIsOptimized = false;
        //}
    }

    void Werkstueck::remove(const IKomponente* k) {
        if(k!=nullptr) {
            Iterator it = komponenten.begin();
            while(it != komponenten.end()) {
                ++it;
                if(*it == k) {
                    (*it)->setParent(nullptr);
                    komponenten.erase(it);

                    // wieso nicht k->setParent(nullptr)

                }
            }
        }
    }

    IKomponente const* Werkstueck::getChild(int i) const{
        IKomponente* erg = nullptr;
        if (i >= 0) {
            Iterator it = komponenten.begin();
            for(int a = 0; a < i && it != komponenten.end(); ++a) {
                ++it;
            }

            erg = *it;
        }
        return erg;
    }

    double Werkstueck::calcPathLength() const
    {
        double erg = 0.0;
        Iterator it = komponenten.begin();
        Iterator before = it;
        erg += this->distance(*it);
        ++it;

        while (it != komponenten.end()) {
            erg += (*before)->distance(*it);
            before = it;
            ++it;
        }

        erg += this->distance(*before);
        return erg;
    }


    double Werkstueck::calcTotalPath() const{
        double erg = 0.0;
        Iterator it = komponenten.begin();

        while (it != komponenten.end())
        {

            erg += (*it)->calcTotalPath();
            ++it;
        }

        erg += calcPathLength();
        return erg;
    }


    // Solve approximately the Traveling Sales Man Problem (TSP) using a
    // nearses neighbour strategy:
    // round trip starts at the linking point of the Werkstueck.
    // then go always to the nearest neighbour among the components
    // that are not already on the new path
    void Werkstueck::optimizePath() {
        if (!pathIsOptimized && komponenten.size() > 0) {
            // first call optimizePath for all Components,
            // which are of type Werkstueck recursively
            Iterator it = komponenten.begin();
            while (it != komponenten.end()) {
                Werkstueck* w = dynamic_cast<Werkstueck*>(*it);
                if (w != nullptr) {
                    w->optimizePath();
                }
                ++it;
            }
            // Now determine a nearest neighbour-sorting
            // of all components
            DeList komponentenSortiert;
            IKomponente* pcurrent = this;
            Iterator nearest = getNearest(pcurrent);
            komponentenSortiert.push_back(*nearest);
            pcurrent = *nearest;
            komponenten.erase(nearest);
            while (komponenten.size() > 0) {
                nearest = getNearest(pcurrent);
                komponentenSortiert.push_back(*nearest);
                pcurrent = *nearest;
                komponenten.erase(nearest);
            }
            komponenten = komponentenSortiert;
            pathIsOptimized = true;
        }
    }


    void Werkstueck::output(std::ostream& os) const{

        std::string blanks = "";    //Leerzeichen entsprechend der Werkstücktiefe
        IKomponente const* parent = this->getParent();

        while (parent != nullptr)
        {
            blanks += "  ";     // Lehrzeichen einfügen solange noch ein Parent vorhanden
            parent = parent->getParent();

        }
        //std::cout << "print 3" << std::endl;
        os << blanks << "Werkstueck:" << std::endl;
        os << blanks << "Verankerung: ";
        Komponente::output(os);
        //os << getXAbsolute() << ", " << getYAbsolute() << ")";
        os << std::endl;
        os << blanks << "height: " << height << ", width: " << width << std::endl;
        os << blanks << "Komponenten:" << std::endl;

        // Durch Liste gehen und ausgeben
        Iterator it = komponenten.begin();

        while (it != komponenten.end())
        {
            if (dynamic_cast<Werkstueck*>(*it) == nullptr)
            {
                os << blanks;
            }

            os << *(*it);

            if (dynamic_cast<Werkstueck*>(*it) == nullptr)
            {
                os << std::endl;
            }

            ++it;
        }
    }


