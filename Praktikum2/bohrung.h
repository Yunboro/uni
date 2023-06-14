#ifndef BOHRUNG_H
#define BOHRUNG_H

#include <iostream>
#include "komponente.h"

class Bohrung : public Komponente {
private:
    double diameter;

public:
    Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);

    double getDiameter() const;

    void output(std::ostream& os) const override;

    ~Bohrung();
};

#endif // BOHRUNG_H
