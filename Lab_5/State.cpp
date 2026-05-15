#include "State.h"
#include "Drinks.h"

using namespace std;

State::State(string n, int mv, int temp , bool g) : Drinks(n, mv) {
    this->temperature = temp;
    this->isGas = g;
    cout << "Constructor State: " << name << endl;
}

State::~State() {
    cout << "Destructor State: " << name << endl;
}

void State::Recommend() {
    cout << "Температура напою: " << temperature << "°C" << endl;
    if (temperature < 4) {
        cout << "Це не діло! Температура занадто низька для напою." << endl;
    } else if (temperature >= 4 && temperature <= 10) {
        cout << "Напій має ідеальну прохолодну температуру!" << endl;
    } else if (temperature > 10 && temperature <= 17) {
        cout << "Напій кімнатної температури!" << endl;
    } else if (temperature > 17) {
        cout << "Напій занадто теплий! Постав в холодильник!" << endl;
    }
}

void State::Info() {
    Drinks::Info();
    cout << "Напі газований: " << (isGas ? "Так" : "Ні") << endl;
}

