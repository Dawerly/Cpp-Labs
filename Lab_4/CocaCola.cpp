#include "CocaCola.h"
#include "Drinks.h"
#include "NonAlco.h"

using namespace std;

CocaCola::CocaCola(string n, int mv, bool g, bool sf, string f) 
    : NonAlco(n, mv, g), SugarFree(sf), flavor(f) {}

void CocaCola::Recommend() {
    NonAlco::Recommend();                   
    if (SugarFree) {
        cout << "Ця Coca-Cola без цукру." << endl;
    } else {
        cout << "Ця Coca-Cola з цукром." << endl;
    }
}

void CocaCola::Info() {
    NonAlco::Info();
    cout << "Смак: " << flavor << endl;
    cout << "Без цукру: " << (SugarFree ? "Так" : "Ні") << endl;
}

void CocaCola::diabeticFriendly() {
    diabeticFriendly(SugarFree);
}

void CocaCola::diabeticFriendly(bool df) {
    if (df)
        cout << "Ця Coca-Cola підходить для діабетиків.\n";
    else
        cout << "Ця Coca-Cola містить цукор — не підходить для діабетиків.\n";
}
