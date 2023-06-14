#include "komponente.h"

#include <iostream>
#include <cmath>

    // Konstruktor mit Default Werten
    Komponente::Komponente(double xPos, double yPos)
        :   parent{nullptr}, x{xPos}, y{yPos}
    {}

    // Getter Methoden
    double Komponente::getX() const{
        return x;
    }

    double Komponente::getXAbsolute() const{
        double xAbs = x;
        if (parent != nullptr) {
            xAbs += parent->getXAbsolute();
        }
        return xAbs;
    }

    double Komponente::getY() const{
        return y;
    }

    double Komponente::getYAbsolute() const{
        double yAbs = y;
        if (parent != nullptr) {
            yAbs += parent->getYAbsolute();
        }
        return yAbs;
    }

    const IKomponente* Komponente::getParent() const{
        return parent;

    }

    // Setter-Methoden
    void Komponente::setParent(const IKomponente* p) {
        parent = p;
    }

    // Übrige Methoden
    double Komponente::calcTotalPath() const{
        return 0.0;
    }

    double Komponente::distance(const IKomponente* k) const{
        double dist = 0;
        if (k != nullptr) {
            double dx = k->getXAbsolute() - this->getXAbsolute();
            double dy = k->getYAbsolute() - this->getYAbsolute();
            //dist = std::sqrt(dx*dx + dy*dy);
            dist = sqrt(pow(dx, 2) + pow(dy, 2));
        }
        return dist;
    }


    // virtual ermöglicht allen Unterklassen die Methode ebenfalls zu verwenden
    // Sie werden dynamisch (erst bei Laufzeit) an eine Speicheradresse gebunden
    void Komponente::output(std::ostream& os) const{
        os << "(" << x << ", "<< y << ")";
    }


    Komponente::~Komponente() {};

