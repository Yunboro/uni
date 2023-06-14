#ifndef IKOMPONENTE_H
#define IKOMPONENTE_H

#include<iostream>

class IKomponente
{
public:
    virtual double calcTotalPath() const = 0;
    virtual double getXAbsolute() const = 0;
    virtual double getYAbsolute() const = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double distance(const IKomponente* k) const = 0;
    virtual const IKomponente* getParent() const = 0;
    virtual void setParent(const IKomponente* p) = 0;
    virtual void output(std::ostream& os) const = 0;

    ~IKomponente();
};

// Überladen Schiebe-Operator als freie Funktion
inline std::ostream& operator<<(std::ostream& os, const IKomponente& ik) {
    ik.output(os);
    return os;
}


#endif // IKOMPONENTE_H
