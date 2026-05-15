#ifndef ENERGY_H
#define ENERGY_H

#include "NonAlco.h"
using namespace std;

class Energy : public NonAlco {
private:
    int CaffeineContent;
public:
    Energy(string n, int mv, bool g, int cc);
    void Recommend() override;
    void Info() override;

};
#endif // ENERGY_H