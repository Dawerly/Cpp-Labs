#ifndef SWEETNESS_H
#define SWEETNESS_H

#include "Drinks.h"
using namespace std;

class Sweetness : virtual public Drinks {
protected:
    int Sugar;
    string flavor;
public:
    Sweetness(string n, int mv, int sf, string f);
    ~Sweetness() override;
    void Recommend() override;
    void Info() override;

    void diabeticFriendly(bool df);
};


#endif // SWEETNESS_H