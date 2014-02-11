#ifndef GREEKS_H
#define GREEKS_H
#include "Option.h"
class Greeks
{
public:
    Greeks(Option& Option, unsigned long prec);
    double Delta(double ecart, double centre) const;
        double Theta(double ecart, double centre) const;
private :
    Option& m_Option;
    unsigned long m_prec;

};


#endif // GREEKS_H
