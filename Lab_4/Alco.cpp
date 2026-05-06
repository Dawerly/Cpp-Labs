#include "Alco.h"
using namespace std;

Alco::Alco(string n, int mv, double ap) : Drinks(n, mv) {
    this->alcoholPercentage = ap;
}

void Alco::Recommend() const {
    cout << "Рекомендація що до вживання: " << name << " має " << alcoholPercentage << "% алкоголю." << endl;
    cout << "Пий відповідально!" << endl;
    if (alcoholPercentage < 9.0) {
        cout << "Можна вживати у міру." << endl;
    } else {
        cout << "Пий з обережністю! Не зловживай!" << endl;
    }
}

void Alco::Info() const {
    Drinks::Info();
    cout << "Вміст алкоголю: " << alcoholPercentage << "%" << endl;
}

void Alco::SlaboAlco(bool sa) const {
    if (sa) {
        cout << name << " є слабоалкогольним напоєм." << endl;
    } else {
        cout << name << " не є слабоалкогольним напоєм." << endl;
    }
}