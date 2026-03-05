#ifndef LOGIC_H
#define LOGIC_H

struct Tovar {
    int grn;
    short int kop;
};

void MNNSHT(int &grn , short int &kop , int sht);
void SUMA(int &grn , short int &kop , short int &total_kop , int &total_grn);
void KOPTOGRN( short int &total_kop , int &total_grn);
void ROUND(short int &total_kop);  
void readTovar(int grn=0 , short int kop=0 , int sht=0); 

#endif