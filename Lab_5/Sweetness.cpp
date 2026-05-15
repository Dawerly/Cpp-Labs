#include "Sweetness.h"
#include "Drinks.h"

using namespace std;

Sweetness::Sweetness(string n, int mv, int sf, string f) : Drinks(n, mv) {
    this->Sugar = sf;
    this->flavor = f;
    cout << "Constructor Sweetness: " << name << endl;
}

Sweetness::~Sweetness() {
    cout << "Destructor Sweetness: " << name << endl;
}

void Sweetness::Recommend() {
    if (Sugar == 0) {
        cout << "Цей напій без цукру" << endl;
    } else {
        cout << "Цей напій з цукром, він містить " << Sugar << " грам цукру" << endl;
    }
}

void Sweetness::Info() {
    cout << "Смак цього напою: " << flavor << endl;
}

void Sweetness::diabeticFriendly(bool df) {
    if (df) {
        cout << "Цей напій підходить для діабетиків!" << endl;
    } else {
        cout << "Цей напій не підходить для діабетиків." << endl;
    }
}
