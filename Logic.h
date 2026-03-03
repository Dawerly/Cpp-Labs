#ifndef LOGIC_H
#define LOGIC_H

struct Tovar {
    int grn;
    short int kop;
};

void MNNSHT(int &grn , short int &kop , int sht);
void SUMA(int &grn , short int &kop , long long &total_kop , long long &total_grn);
void KOPTOGRN(long long &total_kop , long long &total_grn);
void ROUND(long long &total_kop);
void readTovar(int grn , short int kop , int sht);

#endif