#include "fraesung.h"
#include <cmath>


    //Default Parameter immer zum Schluss
    Fraesung::Fraesung(double x, double y, double diam, double l, double a)
        : Bohrung{x,y,diam}, length{l > 0 ? l: 0.0}, angle{a}
    {}

    double Fraesung::getEndX() const
    {
        //x-Anteil von length auf Startwert x addieren
        return getX() + length * std::cos(angle);
    }

    double Fraesung::getEndY() const
    {
        //y-Anteil von length auf Startwert x addieren
        return getY() + length * std::sin(angle);
    }

    inline double Fraesung::getLength() const {
        return length;
    }

    inline double Fraesung::getAngle() const {
        return angle;
    }

    double Fraesung::calcTotalPath() const{
        return 2*getLength();
    }

    void Fraesung::output(std::ostream& os) const{
        os << "Fraesung mit Start: ";
        Komponente::output(os);
        os << " und Endpunkt: ("
           << getEndX() << ", " << getEndY() << "), Durchmesser: "
           << getDiameter();
    }

    Fraesung::~Fraesung() {};
