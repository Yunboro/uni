//#include <iostream>
//#include "ikomponente.h"
//#include "komponente.h"
//#include "bohrung.h"
//#include "fraesung.h"
//#include "komponentenlist.h"

//#include <array>
//#include <cmath>

//using std::cout;
//using std::endl;


//int main() {



//// Länge aus Angabe ermitteln
//constexpr double calcLength(double* coords)
//{
//    double dx = coords[2] - coords[0];
//    double dy = coords[3] - coords[1];
//    return sqrt(dx * dx + dy * dy);
//}

//// Winkel aus Angabe ermitteln
//constexpr double calcAngle(double* coords)
//{
//    return atan2(coords[2] - coords[0], coords[3] - coords[1]);
//}

//int main()
//{
//    // Bohrungen
//    Bohrung b1{1, 2, 8}, b2{2, 6, 4}, b3{10, 8, 7}, b4{7, 2, 5};

//    // Fraesungen
//    // storing the following variables is necessary to calculate lengths and angles
//    double f1Coords[] = {2, 3, 4, 5}; // x1, y1, x2, y2
//    double f2Coords[] = {6, 7, 6, 10};
//    double f3Coords[] = {17, 6, 13, 2};
//    Fraesung f1{2, 3, 5, calcLength(f1Coords), calcAngle(f1Coords)};
//    Fraesung f2{6, 7, 6, calcLength(f2Coords), calcAngle(f2Coords)};
//    Fraesung f3{17, 6, 4, calcLength(f3Coords), calcAngle(f3Coords)};

//    KomponentenList kList {};
//    Komponente* komponenten[] = {&b1, &f1, &b3, &f2, &b4, &f3, &b2};

//    for (const auto& komp : komponenten)
//    {
//        kList.push_back(komp);
//    }

//    cout << kList;

//    return 0;
//}



//int main() {
//    KomponentenList l;
//    Bohrung b1{1, 2, 8}, b2{2, 6, 4}, b3{10, 8, 7}, b4{7, 2, 5};
//    Fraesung f1{2, 3, 5, 2.828, 0.785398}, f2{6, 7, 6, 3, 0}, f3{17, 6, 4, 5.6565, -0.7853916};
//    l.push_back(&b1);
//    l.push_back(&f1);
//    l.push_back(&b3);
//    l.push_back(&f2);
//    l.push_back(&b4);
//    l.push_back(&f3);
//    l.push_back(&b2);

//    for(int i=0; i<l.size(); ++i) {

//        cout << *(l.at(i)) << endl;
//    }
//    return 0;

//}
