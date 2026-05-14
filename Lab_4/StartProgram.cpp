#include "StartProgram.h"
#include "windows.h"
#include "Drinks.h"
#include "Alco.h"
#include "NonAlco.h"
#include "CocaCola.h"
#include "Beer.h"
#include "Energy.h"

#include "Drinks.cpp"     
#include "Alco.cpp"
#include "NonAlco.cpp"
#include "CocaCola.cpp"
#include "Beer.cpp"
#include "Energy.cpp"

using namespace std;

void StartProgram() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Alco *myVodka = new Alco("Горілка", 500, 40.0);
    NonAlco *myJuice = new NonAlco("Сік", 300, false);
    Beer *myBeer = new Beer("Dunkell", 330, 4.5, true);
    CocaCola *myCoke = new CocaCola("Coca-Cola", 500, true, false, "Vanilla");
    Energy *myEnergy = new Energy("Red Bull", 250, true, 80);

    vector<Drinks*> drinkMenu;
    drinkMenu.push_back(myJuice);
    drinkMenu.push_back(myVodka);
    drinkMenu.push_back(myBeer);
    drinkMenu.push_back(myCoke);
    drinkMenu.push_back(myEnergy);

    for (size_t i = 0; i < drinkMenu.size(); ++i) {   
        cout << "=======[Напій №" << i + 1 << "]=======" << endl;
        drinkMenu[i]->Info();
        drinkMenu[i]->Recommend();
        cout << endl;
    }


    delete myVodka;
    delete myJuice;
    delete myBeer;
    delete myCoke;
    delete myEnergy;    
}