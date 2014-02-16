#ifndef DERIV_H
#define DERIV_H

#include "Greeks.h"
#include <iostream>
#include <QVector>

using namespace std;

template<class Greeks>
double Deriv(double centre, double ecart, Greeks& Function)
{
double av(centre-ecart);
double ap(centre+ecart) ;
return (Function(ap)-Function(av))/(ap-av);
}

template<class Greeks>
double Deriv2(double centre, double ecart, Greeks& Function)
{
double av2(centre-2*ecart);
double av(centre-ecart);
double ap(centre+ecart);
double ap2(centre+2*ecart) ;
return -(((Function(av)-Function(av2))/(av-av2))-((Function(ap2)-Function(ap))/(ap2-ap)))/(3*ecart);
}

template<class Greeks>
QVector <double> Tfunc(double debut, double fin, int prec, Greeks& Function)
{
QVector<double> A(prec);
double pas=(fin-debut)/prec;
double axe=debut;
for (int i(0); i<prec; i++)
{
    A[i]=Function(axe);
    axe+=pas;
}
return A;
}

template<class Greeks>
QVector <double> TfuncAxis(double debut, double fin, int prec, Greeks& Function)
{
QVector<double> A(prec);
double pas=(fin-debut)/prec;
double axe=debut;
for (int i(0); i<prec; i++)
{
    A[i]=axe;
    axe+=pas;
}
return A;
}



#endif // DERIV_H
