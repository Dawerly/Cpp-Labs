#ifndef STATE_H
#define STATE_H

#include "Drinks.h"
using namespace std;

class State : virtual public Drinks {
protected:
    bool isGas;
    int temperature;
public:
    State(string n, int mv, int temp , bool g);
    ~State() override;
    void Recommend() override;
    void Info() override;
};


#endif // STATE_H