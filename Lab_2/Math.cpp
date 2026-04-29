#include <cmath>
#include "Math.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

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
        cout << "Trukytnuk vurodzhenui." << endl;
        return;
    }

    double x_circumcenter = ((pow(A.x, 2) + pow(A.y, 2)) * (B.y - C.y) + (pow(B.x, 2) + pow(B.y, 2)) * (C.y - A.y) + (pow(C.x, 2) + pow(C.y, 2)) * (A.y - B.y)) / D;
    double y_circumcenter = ((pow(A.x, 2) + pow(A.y, 2)) * (C.x - B.x) + (pow(B.x, 2) + pow(B.y, 2)) * (A.x - C.x) + (pow(C.x, 2) + pow(C.y, 2)) * (B.x - A.x)) / D;
    cout << "Circumcenter: ( x=" << x_circumcenter << ", y=" << y_circumcenter << ")" << endl;
}

double gaussArea(const Kordunaty &A, const Kordunaty &B, const Kordunaty &C) {
    
    double s_gauss = 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    return s_gauss;
}

void MetodPloshchi(double &s_gauss, Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C)
{
    double ploshDAB = 0.5 * fabs(D.x * (A.y - B.y) + A.x * (B.y - D.y) + B.x * (D.y - A.y));
    double ploshDBC = 0.5 * fabs(D.x * (B.y - C.y) + B.x * (C.y - D.y) + C.x * (D.y - B.y));
    double ploshDCA = 0.5 * fabs(D.x * (C.y - A.y) + C.x * (A.y - D.y) + A.x * (D.y - C.y));

    double suma = ploshDAB + ploshDBC + ploshDCA;
    
    const double EPS = 1e-9;

    if (fabs(suma - s_gauss) < EPS) {
        // Перевіряємо, чи лежить на одній зі сторін (площа одного з підтрикутників ≈ 0)
        if (ploshDAB < EPS || ploshDBC < EPS || ploshDCA < EPS) {
            // Додаткова перевірка через відстані (більш надійна)
            double dAB, dBC, dCA, dDP_AB, dDP_BC, dDP_CA;

            dAB = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
            dBC = sqrt((C.x - B.x)*(C.x - B.x) + (C.y - B.y)*(C.y - B.y));
            dCA = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y));

            dDP_AB = sqrt((D.x - A.x)*(D.x - A.x) + (D.y - A.y)*(D.y - A.y)) +
                     sqrt((D.x - B.x)*(D.x - B.x) + (D.y - B.y)*(D.y - B.y));

            dDP_BC = sqrt((D.x - B.x)*(D.x - B.x) + (D.y - B.y)*(D.y - B.y)) +
                     sqrt((D.x - C.x)*(D.x - C.x) + (D.y - C.y)*(D.y - C.y));

            dDP_CA = sqrt((D.x - C.x)*(D.x - C.x) + (D.y - C.y)*(D.y - C.y)) +
                     sqrt((D.x - A.x)*(D.x - A.x) + (D.y - A.y)*(D.y - A.y));

            bool on_AB = fabs(dDP_AB - dAB) < EPS;
            bool on_BC = fabs(dDP_BC - dBC) < EPS;
            bool on_CA = fabs(dDP_CA - dCA) < EPS;

            if (on_AB || on_BC || on_CA) {
                cout << "Tochka na mezhi (ploshcha)" << endl;
            } else {
                cout << "Tochka zzovni trykutnyka (ploshcha)" << endl;
            }
        }
        else {
            cout << "Tochka vseredyni trykutnyka (ploshcha)" << endl;
        }
    }
    else {
        cout << "Tochka zzovni trykutnyka (ploshcha)" << endl;
    }
}

void MetodVektornohoDobutku(Kordunaty &D, Kordunaty &A, Kordunaty &B, Kordunaty &C)
{
    double VidstABD = (B.x - A.x) * (D.y - A.y) - (B.y - A.y) * (D.x - A.x);
    double VidstBCD = (C.x - B.x) * (D.y - B.y) - (C.y - B.y) * (D.x - B.x);
    double VidstCAD = (A.x - C.x) * (D.y - C.y) - (A.y - C.y) * (D.x - C.x);

    const double EPS = 1e-9;

    // Приводимо дуже малі значення до нуля
    if (fabs(VidstABD) < EPS) VidstABD = 0.0;
    if (fabs(VidstBCD) < EPS) VidstBCD = 0.0;
    if (fabs(VidstCAD) < EPS) VidstCAD = 0.0;

    bool has_pos = (VidstABD > 0.0) || (VidstBCD > 0.0) || (VidstCAD > 0.0);
    bool has_neg = (VidstABD < 0.0) || (VidstBCD < 0.0) || (VidstCAD < 0.0);

    if (has_pos && has_neg) {
        cout << "Tochka zzovni trykutnyka (vektor)" << endl;
    }
    else if (VidstABD == 0.0 || VidstBCD == 0.0 || VidstCAD == 0.0) {
        // Додаткова перевірка, чи справді лежить на стороні (через суму відстаней)
        double dAB, dBC, dCA, dDP_AB, dDP_BC, dDP_CA;  // тимчасові змінні

        // Обчислюємо довжини сторін і відрізків до точки D
        dAB = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
        dBC = sqrt((C.x - B.x)*(C.x - B.x) + (C.y - B.y)*(C.y - B.y));
        dCA = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y));

        dDP_AB = sqrt((D.x - A.x)*(D.x - A.x) + (D.y - A.y)*(D.y - A.y)) +
                 sqrt((D.x - B.x)*(D.x - B.x) + (D.y - B.y)*(D.y - B.y));

        dDP_BC = sqrt((D.x - B.x)*(D.x - B.x) + (D.y - B.y)*(D.y - B.y)) +
                 sqrt((D.x - C.x)*(D.x - C.x) + (D.y - C.y)*(D.y - C.y));

        dDP_CA = sqrt((D.x - C.x)*(D.x - C.x) + (D.y - C.y)*(D.y - C.y)) +
                 sqrt((D.x - A.x)*(D.x - A.x) + (D.y - A.y)*(D.y - A.y));

        bool on_AB = fabs(dDP_AB - dAB) < EPS;
        bool on_BC = fabs(dDP_BC - dBC) < EPS;
        bool on_CA = fabs(dDP_CA - dCA) < EPS;

        if (on_AB || on_BC || on_CA) {
            cout << "Tochka na mezhi (vektor)" << endl;
        } else {
            cout << "Tochka zzovni trykutnyka (vektor)" << endl;
        }
    }
    else {
        cout << "Tochka vseredyni trykutnyka (vektor)" << endl;
    }
}

void Zapusk() {
    SetConsoleCP(65001);         
    SetConsoleOutputCP(65001);
    Kordunaty A, B, C;
    cout << fixed << setprecision(15);

    cout << "\n\n--------------------------------------" << endl;
    cout << "Введіть кординати A(x,y): " << endl;
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

    double s_gauss = gaussArea(A, B, C);
    double p = (vidstAB + vidstAC + vidstBC) / 2.0;
    double ploshcha = t.area();
    if (ploshcha < 1e-9) {
        cout << "--------------------------------------" << endl;
        cout << "Trukytnuk vurodzhenui." << endl;
        cout << "--------------------------------------\n" << endl;
    }

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

        MetodPloshchi(s_gauss, D, A, B, C);
        MetodVektornohoDobutku(D, A, B, C);
        cout << "--------------------------------------" << endl;
    }
}