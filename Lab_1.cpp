#include <iostream>
#include "Logic.cpp"
#include "Logic.h"

using namespace std;

Tovar Tovary[100]; 

int kilkist = 0;

int main() {

    cout << "Vvedit skilki y vas tovariv" << endl; 
    cin >> kilkist;
    for (int i = 0; i < kilkist; i++) {
    cout << "" << i+1 << " Vvedit nazvy, ciny v grn ta kop, ta kilkist tovariv" << endl;  
    cin >> Tovary[i].nazva >> Tovary[i].grn >> Tovary[i].kop >> Tovary[i].sht;
    }

    cout << "\n\n" << endl;
    cout << "======| vash chek |======" << endl;
    cout << "-------------------------------" << endl; 
        for (int i = 0; i < kilkist; i++) {
            cout << Tovary[i].nazva << " " << Tovary[i].grn << ".Grn  " << Tovary[i].kop << ".Kop  " << Tovary[i].sht << "x "<< endl;
            cout << "-------------------------------" << endl;
        }
        
    long long total_grn = 0;
    int total_kop = 0;

    for (int i = 0; i < kilkist; i++) {
    MNNSHT(i);
    SUMA(i); 
    total_grn += Tovary[i].sum_grn;
    total_kop += Tovary[i].sum_kop;
    }

    ROUND(total_kop);
    // KOPTOGRN(total_kop , total_grn);
    while(total_kop >= 100)
    {
        total_kop -= 100;
        total_grn += 1;         
    }

    cout << "Vasha symma:   " << endl;
    cout << total_grn << ".Grn  " << total_kop << ".kop  " << endl;
    cout << "\n\n" << endl;

    return 0;
};