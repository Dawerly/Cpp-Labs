#ifndef ICE_TEE_H
#define ICE_TEE_H

#include "Sweetness.h"
#include "State.h"
#include "Caffeine.h"

using namespace std;

class IceTee : public Sweetness, public State, public Caffeine {
private:
    string teaType;
public:
    IceTee(string n, int mv,int sf, string f, int cc, int temp , bool g, string type);
    ~IceTee() override;
    void Recommend() override;
    void Info() override;
};

#endif // ICE_TEE_H
