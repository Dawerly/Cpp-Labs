#include "Beer.h"
using namespace std;
typedef unsigned char byte;

Beer::Beer(string n, int mv,int ap, bool craft) : Alco(n, mv, ap) {
    this->isCraft = craft;
}

void Beer::Recommend() const {
    Alco::Recommend();
    if (isCraft) {
        cout << "Рекомендація: Ідеально поєднується з м'ясними стравами." << endl;
    } else {
        cout << "Рекомендація: Ідеально поєднується з легкими закусками." << endl;
    }
}

void Beer::Info() const {
    Alco::Info();
    cout << "Яке пиво ?: " << (isCraft ? "Темне" : "Світле") << endl;
}

void Beer::temperature(int t) const {
    cout << "Температура напою: " << t << "°C" << endl;
    if (t < 4) {
        cout << "Це не діло! Постав в холодильник." << endl;
    } else if (t >= 4 && t <= 10) {
        cout << "Пиво має ідеальну прохолодну температуру!" << endl;
    } else if (t > 10 && t <= 17) {
        cout << "Пиво кімнатної температури!" << endl;
    } else if (t > 17) {
        cout << "Пиво занадто тепле! Постав в холодильник!" << endl;
    }
}