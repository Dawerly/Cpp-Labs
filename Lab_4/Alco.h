#ifndef ALCO_H
#define ALCO_H

#include "Drinks.h"
using namespace std;

class Alco : public Drinks {
private:
    double alcoholPercentage;
public:
    Alco(string n, int mv, double ap);
    void Recommend() override;
    void Info() override;

    void SlaboAlco(bool sa);
};
#endif // ALCO_H