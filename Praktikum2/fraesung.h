#ifndef FRAESUNG_H
#define FRAESUNG_H
#include <iostream>
#include <cmath>
#include "bohrung.h"


class Fraesung : public Bohrung {

private:
    double length, angle;
public:
    //Default Parameter immer zum Schluss
    Fraesung(double x, double y, double diam, double l, double a = 0.0 );

    double getEndX() const;
    double getEndY() const;

    inline double getLength() const;
    inline double getAngle() const;

    double calcTotalPath() const override;

    void output(std::ostream& os) const override;

    ~Fraesung();
};

#endif // FRAESUNG_H
