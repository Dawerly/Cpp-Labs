#include "NonAlco.h"
using namespace std;

NonAlco::NonAlco(string n, int mv, bool g) : Drinks(n, mv) {
    this->Gas = g;
}

void NonAlco::Recommend() const {
    cout << "Рекомендація що до вживання: " << name << " є безалкогольним напоєм." << endl;
    cout << "Пий з задоволенням!" << endl;
}

void NonAlco::Info() const {
    Drinks::Info();
    cout << "Газований: " << (Gas ? "Так" : "Ні") << endl;
}

void NonAlco::SALE(bool s) const {
    if (s) {
        cout << name << " Молодець! Взяв по акції." << endl;
    } else {
        cout << name << " Не взяв по акції :( ." << endl;
    }
}
