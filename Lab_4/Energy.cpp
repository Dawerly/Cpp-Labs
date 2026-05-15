#include "Energy.h"
#include "Drinks.h"
#include "NonAlco.h"

using namespace std;
typedef unsigned char byte;

Energy::Energy(string n, int mv, bool g, int cc) : NonAlco(n, mv, g) {
    this->CaffeineContent = cc;
}

void Energy::Recommend() {
    NonAlco::Recommend();
    if (CaffeineContent < 40) {
        cout << "Дитяча доза кофеїну." << endl;
    } else if (CaffeineContent < 160) {
        cout << "Класична доза кофеїну." << endl;
    } else if (CaffeineContent < 250) {
        cout << "Робоча доза кофеїну." << endl;
    } else if (CaffeineContent < 300) {
        cout << "Потужна доза кофеїну." << endl;
    } else if (CaffeineContent < 450) {
        cout << "Крайня небезпека! Не пий! Дуже висока доза кофеїну!" << endl;
    }
}

void Energy::Info() {
    NonAlco::Info();
    cout << "Вміст кофеїну: " << CaffeineContent << " мг" << endl;
}
