#ifndef CLASSES_H
#define CLASSES_H

class Class {
private:
    double a;
    double b;
    double EPS;
    double Func;
    double D_Func;
    double KorinDih;
    double KorinNut;
public:
    Class(void);
    ~Class(void);
    void setA(double a);
    void setB(double b);
    void setEPS(double EPS);
    void setFunc(double Func);
    void setD_Func(double D_Func);
    void setKorinDih(double KorinDih);
    void setKorinNut(double KorinNut);

    void getA(double &a)const;
    void getB(double &b)const;
    void getEPS(double &EPS)const;
    void getFunc(double &Func)const;
    void getD_Func(double &D_Func)const;
    void getKorinDih(double &KorinDih)const;
    void getKorinNut(double &KorinNut)const;

    void Func_calc(double &x);    
    void D_Func_calc(double &x);
    void MetodDihotomi(double a, double b, double EPS);
    void MetodNutona(double x0);
};

void StartProgramm();

#endif // CLASSES_H

// x – 2 + sin(1/x)  [0.9;2]