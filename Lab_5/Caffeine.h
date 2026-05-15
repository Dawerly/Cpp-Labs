#ifndef CAFFEINE_H
#define CAFFEINE_H

#include "Drinks.h"

using namespace std;

class Caffeine : virtual public Drinks {
protected:
    int CaffeineContent;
public:
    Caffeine(string n, int mv, int cc);
    ~Caffeine() override;
    void Recommend() override;
    void Info() override;
};

#endif // CAFFEINE_H