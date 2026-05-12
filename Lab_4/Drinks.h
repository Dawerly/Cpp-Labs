#ifndef DRINKS_H
#define DRINKS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Drinks {
private:
    string name;
    int waterVolume;
public:
    Drinks(string n, int mv);
    virtual ~Drinks() = default;
    virtual void Recommend() const = 0;

    virtual void Info() const;
};

#endif // DRINKS_H