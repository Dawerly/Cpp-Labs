#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Dishes
{
protected:
    Dishes* nextDish;

public:
    Dishes(Dishes* next = nullptr) : nextDish(next) {}
    virtual ~Dishes() = default;

    virtual Dishes* setNext(Dishes* handler) {
        this->nextDish = handler;
        return handler;
    }

    virtual void Dish(const string& name, const vector<string>& ingredients)
    {
        if (this->nextDish) {
            this->nextDish->Dish(name, ingredients);
        } else {
            cout << "Chain: Nobody knows how to cook " << name << ".\n";
        }
    }
};

class Pelmeni : public Dishes
{
public:
    Pelmeni(Dishes* next = nullptr) : Dishes(next) {}

    void Dish(const string& name, const vector<string>& ingredients) override
    {
        if (name == "Pelmeni") 
        {
            if (find(ingredients.begin(), ingredients.end(), "Meat") != ingredients.end()) {
                cout << "Pelmeni: My lovely pelmeni with meat!!!" << endl;
            } else {
                cout << "Pelmeni: I don't like pelmeni without meat." << endl;
            }
        } 
        else 
        {
            Dishes::Dish(name, ingredients);
        }
    }
};

class ApplePie : public Dishes
{
public:
    ApplePie(Dishes* next = nullptr) : Dishes(next) {}

    void Dish(const string& name, const vector<string>& ingredients) override
    {
        if (name == "Apple Pie") 
        {
            if (find(ingredients.begin(), ingredients.end(), "Apples") != ingredients.end()) {
                cout << "Apple Pie: I love Apple Pie!" << endl;
            } else {
                cout << "Apple Pie: I don't like Apple Pie without apples." << endl;
            }
        } 
        else 
        {
            Dishes::Dish(name, ingredients);
        }
    }
};

class HotDog : public Dishes
{
public:
    HotDog(Dishes* next = nullptr) : Dishes(next) {}

    void Dish(const string& name, const vector<string>& ingredients) override
    {
        if (name == "Hot Dog") 
        {
            if (find(ingredients.begin(), ingredients.end(), "Sausage") != ingredients.end()) {
                cout << "Hot Dog: My lovely hot dog with sausage!!!" << endl;
            } else {
                cout << "Hot Dog: I don't like hot dogs without sausage." << endl;
            }
        } 
        else 
        {
            Dishes::Dish(name, ingredients);
        }
    }
};

void ClientOrder(Dishes &chain, const string& name, const vector<string>& ingredients) {
    cout << "Client ordered: " << name << endl;
    chain.Dish(name, ingredients);
    cout << "-----------------------------------" << endl;
}

void StartProgram()
{
    Pelmeni* pelmeni = new Pelmeni();
    ApplePie* applePie = new ApplePie();
    HotDog* hotDog = new HotDog();

    hotDog->setNext(applePie)->setNext(pelmeni);

    ClientOrder(*hotDog, "Hot Dog", { "Sausage", "Bun" });
    ClientOrder(*hotDog, "Hot Dog", { "Ketchup", "Bun" });
    ClientOrder(*hotDog, "Pelmeni", { "Meat", "Flour" });
    ClientOrder(*hotDog, "Apple Pie", { "Apples", "Flour", "Sugar" });
    
    ClientOrder(*hotDog, "Bulka", { "Sausage" }); 

    delete pelmeni;
    delete applePie;
    delete hotDog;
}

int main()
{
    StartProgram();
    return 0;
}