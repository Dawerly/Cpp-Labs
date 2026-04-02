#include <cmath>
#include "Math.h"
#include <iostream>

using namespace std;



// void Vidstan(double &vidstAB, double &vidstAC, double &vidstBC, Kordunaty &A, Kordunaty &B, Kordunaty &C) {
//     vidstAB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
//     vidstAC = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
//     vidstBC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
// }

double distance(const Kordunaty &p1, const Kordunaty &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Trukytnuk &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Trukytnuk::area() const {
    return heronArea(*this);
}

bool Trukytnuk::contains(const Kordunaty &P) const {
    Trukytnuk T1 = {A, B, P};
    Trukytnuk T2 = {B, C, P};
    Trukytnuk T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return fabs(S_main - S_sum) < 1e-9; 
}

void baruscentr(Kordunaty &A, Kordunaty &B, Kordunaty &C) {
    double x_bar, y_bar;
    x_bar = (A.x + B.x + C.x) / 3;
    y_bar = (A.y + B.y + C.y) / 3;
    cout << "Baricentr: ( x=" << x_bar << ", y=" << y_bar << ")" << endl;
}

void Incenter(Kordunaty &A, Kordunaty &B, Kordunaty &C, double &vidstAB, double &vidstAC, double &vidstBC) {
    double x_incenter, y_incenter;
    x_incenter = (vidstBC * A.x + vidstAC * B.x + vidstAB * C.x) / (vidstAB + vidstAC + vidstBC);
    y_incenter = (vidstBC * A.y + vidstAC * B.y + vidstAB * C.y) / (vidstAB + vidstAC + vidstBC);
    cout << "Incenter: ( x=" << x_incenter << ", y=" << y_incenter << ")" << endl;
}

void Circumcenter(Kordunaty &A, Kordunaty &B, Kordunaty &C) {
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    if (D == 0) {
        cout << "Trukytnuk neisnue." << endl;
        return;
    }

    double x_circumcenter = ((pow(A.x, 2) + pow(A.y, 2)) * (B.y - C.y) + (pow(B.x, 2) + pow(B.y, 2)) * (C.y - A.y) + (pow(C.x, 2) + pow(C.y, 2)) * (A.y - B.y)) / D;
    double y_circumcenter = ((pow(A.x, 2) + pow(A.y, 2)) * (C.x - B.x) + (pow(B.x, 2) + pow(B.y, 2)) * (A.x - C.x) + (pow(C.x, 2) + pow(C.y, 2)) * (B.x - A.x)) / D;
    cout << "Circumcenter: ( x=" << x_circumcenter << ", y=" << y_circumcenter << ")" << endl;
}

void MetodPloshchi(double &ploshcha, Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C) 
{
    double ploshDAB, ploshDBC, ploshDCA;
    ploshDAB = 0.5 * fabs(D.x * (A.y - B.y) + A.x * (B.y - D.y) + B.x * (D.y - A.y));
    ploshDBC = 0.5 * fabs(D.x * (B.y - C.y) + B.x * (C.y - D.y) + C.x * (D.y - B.y));
    ploshDCA = 0.5 * fabs(D.x * (C.y - A.y) + C.x * (A.y - D.y) + A.x * (D.y - C.y));

    double suma = ploshDAB + ploshDBC + ploshDCA;

    if (fabs(suma - ploshcha) <= 0.001) 
    {
        if (ploshDAB < 1e-6 || ploshDBC < 1e-6 || ploshDCA < 1e-6) {
            cout << "Tochka znakhodytsia NA MEZHI trykutnyka (Za metodom ploshchi)" << endl;
        } else {
            cout << "Tochka znakhodytsia VSEREDYNI trykutnyka (Za metodom ploshchi)" << endl;
        }
    }
    else if (suma > ploshcha + 0.001) {
        cout << "Tochka znakhodytsia ZZOVNI trykutnyka (Za metodom ploshchi)" << endl;
    } 
    else {
        cout << "Pomylka v obchyslenni ploshch!" << endl;
    }

}


void MetodVektornohoDobutku( Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C) {
    double VidstABD, VidstBCD, VidstCAD;
    VidstABD = (B.x - A.x) * (D.y - A.y) - (B.y - A.y) * (D.x - A.x);
    VidstBCD = (C.x - B.x) * (D.y - B.y) - (C.y - B.y) * (D.x - B.x);
    VidstCAD = (A.x - C.x) * (D.y - C.y) - (A.y - C.y) * (D.x - C.x);

    if (VidstABD > 0 && VidstBCD > 0 && VidstCAD > 0) {
        cout << "Tochka znakhodytsia vseredyni trykutnyka (Za metodom vektornoho dobutku)" << endl;
    }
    else if (VidstABD == 0 || VidstBCD == 0 || VidstCAD == 0) {
        cout << "Tochka znakhodytsia na mezhi (Za metodom vektornoho dobutku)" << endl;
    }
    else if (VidstABD < 0 || VidstBCD < 0 || VidstCAD < 0) {
        cout << "Tochka znakhodytsia zzovni trykutnyka (Za metodom vektornoho dobutku)" << endl;
    }
}


void Zapusk() {
    Kordunaty A, B, C;
    cout << "\n\n--------------------------------------" << endl;
    cout << "Vvedit koordinati A(x,y): " << endl;
    cin >> A.x >> A.y;
    cout << "Vvedit koordinati B(x,y): " << endl;
    cin >> B.x >> B.y;
    cout << "Vvedit koordinati C(x,y): " << endl;
    cin >> C.x >> C.y;
    cout << "--------------------------------------\n" << endl;

    Trukytnuk t = {A, B, C};

    double vidstAB = distance(A, B);
    double vidstAC = distance(A, C);
    double vidstBC = distance(B, C);

    cout << "--------------------------------------" << endl;
    cout << "Vidstan mizh AB: " << vidstAB << endl;
    cout << "Vidstan mizh AC: " << vidstAC << endl; 
    cout << "Vidstan mizh BC: " << vidstBC << endl;
    cout << "--------------------------------------\n" << endl;

    double ploshcha = t.area();
    double p = (vidstAB + vidstAC + vidstBC) / 2.0;

    cout << "--------------------------------------" << endl;
    cout << "Pivperumeter: " << p << endl;
    cout << "Ploshcha troykutnika za heronom: " << ploshcha << endl;
    cout << "--------------------------------------\n" << endl;

    cout << "====[Koordinati centriv trykutnyka:]====" << endl;
    baruscentr(A, B, C);
    Incenter(A, B, C, vidstAB, vidstAC, vidstBC);
    Circumcenter(A, B, C);
    cout << "--------------------------------------\n" << endl;

    cout << "Vedit kilkist tochok dlya perevirku:" << endl;
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Kilkist tochok maie buty bilshoiu za nul.\n";
        return;
    }

    cout << "--------------------------------------" << endl;
    
    for(int i = 1; i <= n; i++) {
        cout << "\nVvedit koordinati tochku D" << i << " (x y):" << endl;
        Kordunaty D;
        cin >> D.x >> D.y;

        cout << "\n--------------------------------------" << endl;
        cout << "Polozhennya tochky D" << i << " vidnosno trykutnyka ABC: " << endl;
        cout << "--------------------------------------" << endl;

        MetodPloshchi(ploshcha, D, A, B, C);
        MetodVektornohoDobutku(D, A, B, C);
        cout << "--------------------------------------" << endl;
    }
}