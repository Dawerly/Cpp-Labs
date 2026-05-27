#ifndef COCACOLA_H
#define COCACOLA_H

#include "NonAlco.h"
using namespace std;

class CocaCola : public NonAlco {
private:
    bool SugarFree;
    string flavor;
public:
    CocaCola(string n, int mv, bool g, bool sf, string f);
    void Recommend() override;
    void Info() override;


    void diabeticFriendly(bool df);
    void diabeticFriendly();
};

#endif // COCACOLA_H