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

    vector<Drinks*> drinkMenu;
    drinkMenu.push_back(new NonAlco("Сік", 300, false));
    drinkMenu.push_back(new Alco("Горілка", 500, 40.0));
    drinkMenu.push_back(new Beer("Dunkell", 330, 4.5, true));
    drinkMenu.push_back(new CocaCola("Coca-Cola", 500, true, false, "Vanilla"));
    drinkMenu.push_back(new Energy("Red Bull", 250, true, 80));

    for (size_t i = 0; i < drinkMenu.size(); ++i) {   
        cout << "=======[Напій №" << i + 1 << "]=======" << endl;
        drinkMenu[i]->Info();
        drinkMenu[i]->Recommend();
        cout << endl;
    }

    for (size_t i = 0; i < drinkMenu.size(); ++i) {
        delete drinkMenu[i];
    }
}