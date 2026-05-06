#ifndef BEER_H
#define BEER_H

#include "Alco.h"
using namespace std;

class Beer : public Alco {
private:
    bool isCraft;
public:
    Beer(string n, int mv,int ap, bool craft);
    void Recommend() const override;
    void Info() const override;

    void temperature(int t) const;
};

#endif // BEER_H