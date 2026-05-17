#include "Classes.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

using namespace std;

Class::Class() {}
Class::~Class() {}

void Class::setA(double a){ this->a = a; }
void Class::setB(double b){ this->b = b; }
void Class::setEPS(double EPS){ this->EPS = EPS; }

void Class::getA(double &a)const{ a = this->a; }
void Class::getB(double &b)const{ b = this->b; }
void Class::getEPS(double &EPS)const{ EPS = this->EPS; }
void Class::getFunc(double &Func)const{ Func = this->Func; }
void Class::getD_Func(double &D_Func)const{ D_Func = this->D_Func; }
void Class::getKorinDih(double &KorinDih)const{ KorinDih = this->KorinDih; }
void Class::getKorinNut(double &KorinNut)const{ KorinNut = this->KorinNut; }

void Class::Func_calc(double &x){           
    auto f = [](double x) -> double {
        if (x == 0.0) return NAN;
        return x - 2.0 + sin(1.0 / x);
    };
    Func = f(x);
}

void Class::D_Func_calc(double &x){        
    auto df = [](double x) -> double {
        if (x == 0.0) return NAN;
        return 1.0 - cos(1.0 / x) / (x * x);
    };
    D_Func = df(x);
}

void Class::MetodDihotomi(double a, double b, double EPS){
    auto isZero = [](double val) -> bool {
        return fabs(val) <= 1e-10;
    };

    Func_calc(a);                    
    double Func_a = Func;

    Func_calc(b);                    
    double Func_b = Func;

    if(std::isnan(Func_a) || std::isnan(Func_b)){
        cout << "-------------------[ERROR]-------------------" << endl;
        cout << "Відсутність функції на кінцях інтервалу" << endl;
        cout << "---------------------------------------------" << endl;
        return;
    }

    if (isZero(Func_a)) {
        KorinDih = a;
        return;
    }

    if (isZero(Func_b)) {
        KorinDih = b;
        return;
    }

    if (Func_a * Func_b > 0) {
        cout << "---------------------------------------------" << endl;
        cout << "Немає кореня на цьому інтервалі" << endl;
        cout << "---------------------------------------------" << endl;
        return;
    }

    double c;
    int i = 0;
    const int maxIter = 9999;

    while((b - a > EPS) && (i < maxIter)) {
        c = (a + b) / 2.0;
        Func_calc(c);               
        double Func_c = Func;

        if (isZero(Func_c)) {
            KorinDih = c;
            return;
        }

        if (Func_a * Func_c < 0) {
            b = c;
            Func_b = Func_c;
        } else {
            a = c;
            Func_a = Func_c;
        }
        i++;
    }
    KorinDih = c;
}

void Class::MetodNutona(double x0){
    auto isZero = [](double val) -> bool {
        return fabs(val) <= 1e-10;
    };

    double x = x0;
    int iteration = 9999;

    for (int i = 0; i < iteration; i++) {
        Func_calc(x);                   
        double Func_x0 = Func;

        D_Func_calc(x);                 
        double D_Func_x0 = D_Func;

        if (isZero(D_Func_x0)) {
            cout << "---------------------------------------------" << endl;
            cout << "Похідна дорівнює нулю. Метод Н'ютона не може бути застосований." << endl;
            cout << "---------------------------------------------" << endl;
            return;
        }

        double x1 = x - Func_x0 / D_Func_x0;
        cout << "Ітерація " << i + 1 << ": x = " << x1 << endl;

        if (isZero(x1 - x)) {
            KorinNut = x1;
            return;
        }

        x = x1;
    }
    KorinNut = x;
}

void StartProgramm(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double a, b, EPS;

    cout << "\n---------------------------------------------" << endl;
    cout << "Введіть a: " << endl;
    cin >> a;
    cout << "---------------------------------------------" << endl;
    cout << "Введіть b: " << endl;
    cin >> b;
    cout << "---------------------------------------------" << endl;
    cout << "Введіть EPS: " << endl;
    cin >> EPS;
    cout << "---------------------------------------------\n" << endl;

    if(EPS <= 0){
        cout << "\n-------------------[ERROR]-------------------" << endl;
        cout << "Помилка: EPS має бути додатнім числом." << endl;
        cout << "---------------------------------------------\n" << endl;
        return;
    }
    if (a > b) {
        cout << "---------------------------------------------" << endl;
        cout << "Попередження: Початок відрізка більший за кінець. Міняємо їх місцями." << endl;
        cout << "---------------------------------------------\n" << endl;
        std::swap(a, b);
    }

    Class* o = new Class();
    o->setA(a);
    o->setB(b);
    o->setEPS(EPS);
    o->MetodDihotomi(a, b, EPS);
    o->MetodNutona(50.0);
    
    double KorinDih, KorinNut;
    o->getKorinDih(KorinDih);
    o->getKorinNut(KorinNut);
    
    cout << fixed << setprecision(20);

    cout << "---------------------------------------------" << endl;
    cout << "Наша функція: f(x) = x - 2 + sin(1/x)" << endl;
    cout << "Досліджуємо функцію на інтервалі [" << a << ", " << b << "]:" << endl;
    cout << "---------------------------------------------\n" << endl;

    cout << "==============[Метод Дихотомії]===============" << endl;
    if(std::isnan(KorinDih)){
        cout << "Корінь не знайдено." << endl;
    } else {
        cout << "Приблизний корінь: " << KorinDih << endl;
    }
    cout << "---------------------------------------------\n" << endl;

    cout << "===============[Метод Н'ютона]================" << endl;
    if(std::isnan(KorinNut)){
        cout << "Корінь не знайдено." << endl;
    } else {
        cout << "Приблизний корінь: " << KorinNut << endl;
    }
    cout << "---------------------------------------------\n" << endl;
    delete o;
}