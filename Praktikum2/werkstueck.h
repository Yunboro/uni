#ifndef WERKSTUECK_H
#define WERKSTUECK_H
#include "komponente.h"
#include "delist.h"
#include "iterator.h"

class Werkstueck : public Komponente {
private:
    double height, width;
    bool pathIsOptimized;
    DeList komponenten;

    Iterator getNearest(const IKomponente* pk) const;


public:
    Werkstueck(double xPos = 0, double yPos = 0, double h = 1.0, double w = 1.0);

    double getHeight() const;
    double getWidth() const;
    void add(IKomponente* k);
    void remove(const IKomponente* k);

    IKomponente const* getChild(int i) const;

    double calcPathLength() const;
    double calcTotalPath() const override;

    void optimizePath();

    void output(std::ostream& os) const override;


};

#endif // WERKSTUECK_H


