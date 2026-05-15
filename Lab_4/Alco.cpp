#include "Alco.h"
#include "Drinks.h"

using namespace std;

Alco::Alco(string n, int mv, double ap) : Drinks(n, mv) {
    this->alcoholPercentage = ap;
}

void Alco::Recommend() {
    cout << "Рекомендація що до вживання: " << name << " має " << alcoholPercentage << "% алкоголю." << endl;
    cout << "Пий відповідально!" << endl;
    if (alcoholPercentage < 9.0) {
        cout << "Можна вживати у міру." << endl;
    } else {
        cout << "Пий з обережністю! Не зловживай!" << endl;
    }
}

void Alco::Info() {
    Drinks::Info();
    cout << "Вміст алкоголю: " << alcoholPercentage << "%" << endl;
}

void Alco::SlaboAlco(bool sa) {
    if (sa) {
        cout << name << " є слабоалкогольним напоєм." << endl;
    } else {
        cout << name << " не є слабоалкогольним напоєм." << endl;
    }
}