#include "Logic.h"
#include <iostream>
#include <fstream>

using namespace std;

int sht;

void MNNSHT(int &grn , short int &kop , int sht)  
{
    kop = kop * sht;
    grn = grn * sht;
}

void SUMA(int &grn , short int &kop , long long &total_kop , long long &total_grn)
{
    total_grn += grn;
    total_kop += kop;   
}

void KOPTOGRN(long long &total_kop , long long &total_grn)
{
    while(total_kop >= 100)
    {
        total_kop -= 100;
        total_grn += 1;         
    }
}

void ROUND(long long &total_kop)
{
    int ost = total_kop % 10;
    int b = 10-ost;
    if (ost == 1 || ost == 2 || ost == 3)  total_kop -= ost;   
    if (ost == 4 || ost == 5|| ost == 6 || ost == 7 || ost == 8 || ost == 9) total_kop+=b;
}

void readTovar(int grn , short int kop , int sht) {
    FILE *file = fopen("C:\\Cpp-Labs\\Lab_1\\Chek.txt", "r"); // Встановіть власний шлях до файлу Chek.txt

    if (file == NULL) {
        cout << "Ne vdalos otvoryty fail Chek.txt" << endl;
        return;
    }

    cout << "\n\n=======| vash chek |=======" << endl;
    cout << "---------------------------" << endl;

    char nazva[50];
    long long total_kop = 0;
    long long total_grn = 0;

    while (fscanf(file, "%49s %d %hi %d", nazva, &grn, &kop, &sht) == 4) {

        if (grn < 0 || kop < 0 || sht < 0) {
            cout << "Error :(  Takogo tovara neisnue." << endl;
            cout << "---------------------------" << endl;
            continue;
        }
        cout << nazva << "   " << grn << "grn  " << kop << "kop  " << sht << "x" << endl;
        cout << "---------------------------" << endl;

        MNNSHT(grn, kop, sht);
        SUMA(grn, kop, total_kop, total_grn);
        KOPTOGRN(total_kop, total_grn);

    }

    fclose(file);

    ROUND(total_kop);
    KOPTOGRN(total_kop, total_grn);

    cout << "Vasha syma: " << total_grn << "grn  " << total_kop << "kop\n\n" << endl;
}


