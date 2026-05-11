#include "Drinks.h"
using namespace std;

Drinks::Drinks(string n, int mv) {
    this->name = n;
    this->waterVolume = mv;
}

void Drinks::Info() const {
    cout << "Назва: " << name << ", Об'єм води: " << waterVolume << " мл." << endl;
}
