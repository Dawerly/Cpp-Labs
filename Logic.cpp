#include "Logic.h"


bool MNNSHT(int i)  
{
    Tovary[i].kop = Tovary[i].kop * Tovary[i].sht;
    Tovary[i].grn = Tovary[i].grn * Tovary[i].sht;
    return true;
}

bool SUMA(int i)
{
    Tovary[i].sum_grn = Tovary[i].grn;
    Tovary[i].sum_kop = Tovary[i].kop;
    return true;
}

bool ROUND(int &total_kop)
{
    int ost = total_kop % 10;
    int b = 10-ost;
    if (ost == 1 || ost == 2 || ost == 3)  total_kop -= ost;   
    if (ost == 4 || ost == 5|| ost == 6 || ost == 7 || ost == 8 || ost == 9) total_kop+=b;
    return true;
}

// bool KOPTOGRN(int &total_kop , int &total_grn)
// {
//     while(total_kop >= 100)
//     {
//         total_kop -= 100;
//         total_grn += 1;         
//     }
//     return true;
// }