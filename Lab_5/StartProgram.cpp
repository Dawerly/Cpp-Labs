#include "StartProgram.h"
#include "windows.h"
#include "Drinks.h"
#include "Sweetness.h"
#include "State.h"
#include "Caffeine.h"
#include "IceTee.h"
#include "Kvass.h"

#include "Drinks.cpp"     
#include "Sweetness.cpp"
#include "State.cpp"
#include "Caffeine.cpp"
#include "IceTee.cpp"
#include "Kvass.cpp"

using namespace std;

void StartProgram() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "\n=======[Constructor]=======" << endl;
    //Назва, Об'єм води, Смак, Вміст цукру, Вміст кофеїну, Температура, Газований, Тип чаю
    Drinks* iceTee = new IceTee("Lipton", 300, 5, "Лимон", 50, 10, true, "Чорний");
    cout <<"=============================="<< endl;


    cout << "\n=========[Напій №1]==========" << endl;
    iceTee->Info();
    iceTee->Recommend();
    cout <<"================================\n"<< endl;

    cout << "=======[Destruction]=======" << endl;
    delete iceTee;
    cout <<"=============================="<< endl;

    cout << "\n=======[Constructor]=======" << endl;
    //Назва, Об'єм води, Смак, Вміст цукру, Вміст кофеїну, Температура, Газований, Вид квасу
    Drinks* kvass = new Kvass("Квас Тарас", 500, 3, "Світлий", 20, 15, true, true);
    cout <<"=============================="<< endl;

    cout << "\n=========[Напій №2]==========" << endl;
    kvass->Info();
    kvass->Recommend();
    cout <<"================================\n"<< endl;

    cout << "=======[Destruction]=======" << endl;
    delete kvass;
    cout <<"=============================="<< endl;
 
}