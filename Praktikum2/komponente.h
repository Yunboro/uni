#ifndef KOMPONENTE_H
#define KOMPONENTE_H
#include <iostream>
#include "ikomponente.h"
#include <cmath>



class Komponente : public IKomponente {

private:
    const IKomponente* parent;
    double x, y;


public:

    // Konstruktor mit Default Werten
    Komponente(double xPos = 0.0, double yPos = 0.0);

    // Getter Methoden
    double getX() const;
    double getXAbsolute() const;
    double getY() const;
    double getYAbsolute() const;

    IKomponente const* getParent() const;

    // Setter-Methoden
    void setParent(const IKomponente* p);

    // Übrige Methoden
    double calcTotalPath() const;

    double distance(const IKomponente* k) const;

    void output(std::ostream& os) const override;

    ~Komponente();
};

#endif // VPP_PRAK_1_H
