#ifndef KVASS_H
#define KVASS_H

#include "Sweetness.h"
#include "State.h"
#include "Caffeine.h"

using namespace std;

class Kvass : public Sweetness, public State, public Caffeine {
private:
    bool isCraft;
public:
    Kvass(string n, int mv,int sf, string f, int cc, int temp , bool g, bool craft);
    ~Kvass() override;
    void Recommend() override;
    void Info() override;
};


#endif // KVASS_H