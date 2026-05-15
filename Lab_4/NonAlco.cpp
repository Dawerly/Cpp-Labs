#include "NonAlco.h"
#include "Drinks.h"
using namespace std;

NonAlco::NonAlco(string n, int mv, bool g) : Drinks(n, mv) {
    this->Gas = g;
}

void NonAlco::Recommend() {
    cout << "Рекомендація що до вживання: " << name << " є безалкогольним напоєм." << endl;
    cout << "Пий з задоволенням!" << endl;
}

void NonAlco::Info() {
    Drinks::Info();
    cout << "Газований: " << (Gas ? "Так" : "Ні") << endl;
}

void NonAlco::SALE(bool s) {
    if (s) {
        cout << name << " Молодець! Взяв по акції." << endl;
    } else {
        cout << name << " Не взяв по акції :( ." << endl;
    }
}
