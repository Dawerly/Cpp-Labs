#ifndef LOGIC_H
#define LOGIC_H

struct Tovar {

    int grn;
    short int kop;
    char nazva[25];
    int sht;
    int sum_grn;
    short int sum_kop;
};

extern Tovar Tovary[100];

bool MNNSHT(int i);
bool SUMA(int i);
bool ROUND(int &total_kop);
// bool KOPTOGRN(int &total_kop , int &total_grn);

#endif