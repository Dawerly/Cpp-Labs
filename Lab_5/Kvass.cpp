#include "Kvass.h"
#include "Drinks.h"
#include "Sweetness.h"
#include "State.h"
#include "Caffeine.h"

using namespace std;

Kvass::Kvass(string n, int mv, int sf, string f, int cc, int temp, bool g, bool craft) : Drinks(n, mv), Sweetness(n, mv, sf, f), Caffeine(n, mv, cc) , State(n, mv, temp, g) {
    this->isCraft = craft;
    cout << "Constructor Kvass: " << name << endl;
}

Kvass::~Kvass() {
    cout << "Destructor Kvass: " << name << endl;
}

void Kvass::Recommend() {
    Sweetness::Recommend();
    State::Recommend();
    Caffeine::Recommend();
    if (isCraft) {
        cout << "Рекомендація: Ідеально поєднується з м'ясними стравами." << endl;
    } else {
        cout << "Рекомендація: Ідеально поєднується з легкими закусками." << endl;
    }
}

void Kvass::Info() {
    Sweetness::Info();
    State::Info();
    Caffeine::Info();
    cout << "Який Квас ?: " << (isCraft ? "Темний" : "Світлий") << endl;
}

