#include "CocaCola.h"
using namespace std;

CocaCola::CocaCola(string n, int mv, bool g, bool sf, string f) : NonAlco(n, mv, g) {
    this->SugarFree = sf;
    this->flavor = f;
}

void CocaCola::Recommend() const {
    NonAlco::Recommend();
    if (SugarFree) {
        cout << "Ця Coca-Cola без цукру" << endl;
    } else {
        cout << "Ця Coca-Cola з цукром" << endl;
    }
}

void CocaCola::Info() const {
    NonAlco::Info();
    cout << "Смак цієї Coca-Cola: " << flavor << endl;
}

void CocaCola::diabeticFriendly(bool df) const {
    if (df) {
        cout << "Ця Coca-Cola підходить для діабетиків!" << endl;
    } else {
        cout << "Ця Coca-Cola не підходить для діабетиків." << endl;
    }
}