#ifndef MATH_H
#define MATH_H

struct Kordunaty {
    double x;
    double y;
};
struct Trukytnuk {
    Kordunaty A;
    Kordunaty B;
    Kordunaty C;
};

void Vidstan(double &vidstAB, double &vidstAC, double &vidstBC, Kordunaty &A, Kordunaty &B, Kordunaty &C);
void Heron(double &vidstAB, double &vidstAC, double &vidstBC, double &p, double &ploshcha);
void baruscentr(Kordunaty &A, Kordunaty &B, Kordunaty &C);
void Incenter(Kordunaty &A, Kordunaty &B, Kordunaty &C, double &vidstAB, double &vidstAC, double &vidstBC);
void Circumcenter(Kordunaty &A, Kordunaty &B, Kordunaty &C);
void MetodPloshchi( double &ploshcha, Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C);
void MetodVektornohoDobutku(Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C);
void Zapusk();

#endif // MATH_H