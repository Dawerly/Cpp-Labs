#ifndef ALCO_H
#define ALCO_H

#include "Drinks.h"
using namespace std;

class Alco : public Drinks {
private:
    double alcoholPercentage;
public:
    Alco(string n, int mv, double ap);
    void Recommend() const override;
    void Info() const override;

    void SlaboAlco(bool sa) const;
};
#endif // ALCO_H