#ifndef COCACOLA_H
#define COCACOLA_H

#include "NonAlco.h"
using namespace std;
typedef unsigned char byte;

class CocaCola : public NonAlco {
private:
    bool SugarFree;
    string flavor;
public:
    CocaCola(string n, int mv, bool g, bool sf, string f);
    void Recommend() const override;
    void Info() const override;

    void diabeticFriendly(bool df) const;
};

#endif // COCACOLA_H