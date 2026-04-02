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

    double area() const;
    bool contains(const Kordunaty &P) const;
};

double distance(const Kordunaty &p1, const Kordunaty &p2);
void Heron(const Trukytnuk &t);

// void Vidstan(double &vidstAB, double &vidstAC, double &vidstBC, Kordunaty &A, Kordunaty &B, Kordunaty &C);
void baruscentr(Kordunaty &A, Kordunaty &B, Kordunaty &C);
void Incenter(Kordunaty &A, Kordunaty &B, Kordunaty &C, double &vidstAB, double &vidstAC, double &vidstBC);
void Circumcenter(Kordunaty &A, Kordunaty &B, Kordunaty &C);
void MetodPloshchi( double &ploshcha, Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C);
void MetodVektornohoDobutku(Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C);
void Zapusk();

#endif // MATH_H