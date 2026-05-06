#ifndef NONALCO_H
#define NONALCO_H

#include "Drinks.h"
using namespace std;
typedef unsigned char byte;

class NonAlco : public Drinks {
private:
    bool Gas;
public:
    NonAlco(string n, int mv, bool g);
    void Recommend() const override;
    void Info() const override;

    void SALE(bool s) const;
};

#endif // NONALCO_H