#include "IceTee.h"
#include "Drinks.h"
#include "Sweetness.h"
#include "State.h"
#include "Caffeine.h"

using namespace std;

IceTee::IceTee(string n, int mv, int sf, string f, int cc, int temp, bool g, string type) : Drinks(n, mv), Sweetness(n, mv, sf, f), Caffeine(n, mv, cc), State(n, mv, temp, g) {
    this->teaType = type;
    cout << "Constructor IceTee: " << name << endl;
}

IceTee::~IceTee() {
    cout << "Destructor IceTee: " << name << endl;
}
    
void IceTee::Recommend() {
    Sweetness::Recommend();
    State::Recommend();
    Caffeine::Recommend();
    cout << "Рекомендація: " << teaType << " холодний чай пийте зі своїми улюбленим печивом." << endl;
}

void IceTee::Info() {
    Sweetness::Info();
    State::Info();
    Caffeine::Info();
    cout << "Тип чаю: " << teaType << endl;
}


