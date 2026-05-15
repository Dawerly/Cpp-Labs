#ifndef BEER_H
#define BEER_H

#include "Alco.h"
using namespace std;

class Beer : public Alco {
private:
    bool isCraft;
public:
    Beer(string n, int mv,int ap, bool craft);
    void Recommend() override;
    void Info() override;

    void temperature(int t);
};

#endif // BEER_H