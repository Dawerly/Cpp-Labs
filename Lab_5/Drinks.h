#ifndef DRINKS_H
#define DRINKS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Drinks {
protected:
    string name;
    int waterVolume;
public:
    Drinks(string n, int mv);
    virtual ~Drinks();
    virtual void Recommend();
    virtual void Info();
};


#endif // DRINKS_H