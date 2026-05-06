#ifndef ENERGY_H
#define ENERGY_H

#include "NonAlco.h"
using namespace std;
typedef unsigned char byte;

class Energy : public NonAlco {
private:
    int CaffeineContent;
public:
    Energy(string n, int mv, bool g, int cc);
    void Recommend() const override;
    void Info() const override;

};

#endif // ENERGY_H