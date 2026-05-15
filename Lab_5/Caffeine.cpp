#include "Caffeine.h"
#include "Drinks.h"

using namespace std;

Caffeine::Caffeine(string n, int mv, int cc) : Drinks(n, mv) {
    this->CaffeineContent = cc;
    cout << "Constructor Caffeine: " << name << endl;
}

Caffeine::~Caffeine() {
    cout << "Destructor Caffeine: " << name << endl;
}

void Caffeine::Recommend() {
    if (CaffeineContent == 0) {
        cout << "Відсутній кофеїн." << endl;   
    } else if (CaffeineContent < 40) {
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

void Caffeine::Info() {
    cout << "Вміст кофеїну: " << CaffeineContent << " мг" << endl;
}


