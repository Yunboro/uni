#include <iostream>
#include "ikomponente.h"
#include "komponente.h"
#include "bohrung.h"
#include "fraesung.h"
#include "werkstueck.h"

#include <array>
#include <cmath>

using std::cout;
using std::endl;

constexpr double calcLength(double* coords) {
    double dx = coords[2] - coords[0];
    double dy = coords[3] - coords[1];
    return sqrt(dx * dx + dy * dy);
}

constexpr double calcAngle(double* coords) {
    return atan2(coords[2] - coords[0], coords[3] - coords[1]);
}
int main() {
    // Bohrungen der Form{x,y,diam}
    Bohrung b1(1,2,8);
    Bohrung b2{2,6,4};
    Bohrung b3{10,8,7};
    Bohrung b4{7,2,5};
    Bohrung b5{1,2,6};
    Bohrung b6{5,1,8};
    Bohrung b7{5,2.5,8};
    Bohrung b8{6,0.5,6};

    //Fräsungen Anfangs- und Endkoordinaten
    double coordsF1[] = {2, 3, 4, 5};   // x1, y1, x2, y2
    double coordsF2[] = {6, 7, 9, 7};
    double coordsF3[] = {17, 6, 13, 2};
    double coordsF4[] = {9, 13, 7, 14};
    double coordsF5[] = {14, 14, 13, 15};

    //Fraesungen der Form {x,y,diam,length,angle}
    Fraesung f1{2, 3, 5, calcLength(coordsF1), calcAngle(coordsF1)};
    Fraesung f2{6, 7, 6, sqrt(9), 0};
    Fraesung f3{17, 6, 4, calcLength(coordsF3), calcAngle(coordsF3)};
    Fraesung f4{3, 3, 3, calcLength(coordsF4), calcAngle(coordsF4)};
    Fraesung f5{1, 2, 4, calcLength(coordsF5), calcAngle(coordsF5)};

    //Werkstücke der Form {x, y, height, width}
    Werkstueck w0{0, 0, 18, 25};
    Werkstueck w1{6, 10, 7, 18};
    Werkstueck w2{6, 3, 3, 10};



    // w0 auffüllen
    Komponente* komponentenW0[] = {&b1, &b2, &b3, &b4, &f1, &f2, &f3};
    for (const auto& komp : komponentenW0)
    {
        w0.add(komp);
    }

    // w1 auffüllen (keine Teilwerkstücke)
    Komponente* komponentenW1[] = {&b5, &b6, &f4};
    for (const auto& komp : komponentenW1)
    {
        w1.add(komp);
    }

    // w2 auffüllen (keine Teilwerkstücke)
    Komponente* komponentenW2[] = {&b7, &b8, &f5};
    for (const auto& komp : komponentenW2)
    {
        w2.add(komp);
    }

    // Teilwerkstücke auffüllen
    w0.add(&w1);
    w1.add(&w2);

    cout << w0 << endl;

    // Ausgabe calcTotalPath() und CalcPathLength() aller Werkstücke
    Werkstueck* werkstuecke1[] = {&w0, &w1, &w2};
    int i = 0;
    for(const auto& ws : werkstuecke1) {
        cout << "total Path w" << i << ": " << ws->calcTotalPath() << endl;
        cout << "Path length w" << i << ": " << ws->calcPathLength() << endl;
        ++i;
    }
    cout << endl;



    cout << "Optimierung der Pfad-Laenge:" << endl;

    w0.optimizePath();
    Werkstueck* werkstuecke2[] = {&w0, &w1, &w2};

    cout << w0 << endl;

    i = 0;
    for(const auto& ws : werkstuecke2) {
        cout << "total Path w" << i << ": " << ws->calcTotalPath() << endl;
        cout << "Path length w" << i << ": " << ws->calcPathLength() << endl;
        ++i;
    }





    return 0;

}
