#ifndef DERIV_H
#define DERIV_H

#include "Greeks.h"
#include <iostream>

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


#endif // DERIV_H
