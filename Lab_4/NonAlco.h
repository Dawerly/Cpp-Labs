#ifndef NONALCO_H
#define NONALCO_H

#include "Drinks.h"
using namespace std;

class NonAlco : public Drinks {
private:
    bool Gas;
public:
    NonAlco(string n, int mv, bool g);
    void Recommend() override;
    void Info() override;

    void SALE(bool s);
};

#endif // NONALCO_H