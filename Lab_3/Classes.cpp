#include <iostream>
#include "Classes.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

Class::Class(){}
Class::~Class(){}

void Class::setA(double a){ this->a = a; }
void Class::setB(double b){ this->b = b; }
void Class::setEPS(double EPS){ this->EPS = EPS; }
void Class::setFunc(double Func){ this->Func = Func; }
void Class::setD_Func(double D_Func){ this->D_Func = D_Func; }
void Class::setKorinDih(double KorinDih){ this->KorinDih = KorinDih; }
void Class::setKorinNut(double KorinNut){ this->KorinNut = KorinNut; }

void Class::getA(double &a)const{ a = this->a; }
void Class::getB(double &b)const{ b = this->b; }
void Class::getEPS(double &EPS)const{ EPS = this->EPS; }
void Class::getFunc(double &Func)const{ Func = this->Func; }
void Class::getD_Func(double &D_Func)const{ D_Func = this->D_Func; }
void Class::getKorinDih(double &KorinDih)const{ KorinDih = this->KorinDih; }
void Class::getKorinNut(double &KorinNut)const{ KorinNut = this->KorinNut; }

bool BilaNolia(double a, double b){
    double diff = abs(a - b);
    return (diff <= 1e-10); 
}

void Class::Func_calc(double &x){           
    double result = x - 2 + sin(1/x);
    Func = result;
}

void Class::D_Func_calc(double &x){        
    double result = 1 - cos(1/x) / (x * x);
    D_Func = result;
}

void Class::MetodDihotomi(double a, double b, double EPS){
    int iteration = 9999;

    Func_calc(a);                    
    double Func_a = Func;
    getFunc(Func_a);

    Func_calc(b);                    
    double Func_b = Func;
    getFunc(Func_b);

    if(std::isnan(Func_a) || std::isnan(Func_b)){
        cout << "-------------------[ERROR]-------------------" << endl;
        cout << "Відсутність функції на кінцях інтервалу" << endl;
        cout << "---------------------------------------------" << endl;
        return;
    }

    if (BilaNolia(Func_a, 0.0)) {
        setKorinDih(a);
        return;
    }

    if (BilaNolia(Func_b, 0.0)) {
        setKorinDih(b);
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
    while((b-a > EPS) && (i < iteration)) {
        c = (a + b) / 2;
        Func_calc(c);               
        double Func_c = Func;
        getFunc(Func_c);

        if (BilaNolia(Func_c, 0.0)) {
            setKorinDih(c);
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
    setKorinDih(c);
}

void Class::MetodNutona(double x0){
    int iteration = 9999;
    double x1;

    for (int i = 0; i < iteration; i++) {
        Func_calc(x0);                   
        double Func_x0 = Func;
        getFunc(Func_x0);

        D_Func_calc(x0);                 
        double D_Func_x0 = D_Func;
        getD_Func(D_Func_x0);

        if (BilaNolia(D_Func_x0, 0.0)) {
            cout << "---------------------------------------------" << endl;
            cout << "Похідна дорівнює нулю. Метод Н'ютона не може бути застосований." << endl;
            cout << "---------------------------------------------" << endl;
            return;
        }

        x1 = x0 - Func_x0 / D_Func_x0;

        if (BilaNolia(x1 - x0, 0.0)) {
            setKorinNut(x1);
            return;
        }

        x0 = x1;
    }
    setKorinNut(x0);
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
    o->MetodNutona(a);
    
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
