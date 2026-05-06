#include "Drinks.h"
using namespace std;
typedef unsigned char byte;

Drinks::Drinks(string n, int mv) {
    this->name = n;
    this->waterVolume = mv;
}

void Drinks::Info() const {
    cout << "Назва: " << name << ", Об'єм води: " << waterVolume << " мл." << endl;
}
