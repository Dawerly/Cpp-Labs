#include "Drinks.h"
using namespace std;

Drinks::Drinks(string n, int mv) {
    this->name = n;
    this->waterVolume = mv;
    cout << "Constructor Drinks: " << name << endl;
}

Drinks::~Drinks() {
    cout << "Destructor Drinks: " << name << endl;
}

void Drinks::Info() {
    cout << "Назва: " << name << ", Об'єм води: " << waterVolume << " мл." << endl;
}

void Drinks::Recommend() {}