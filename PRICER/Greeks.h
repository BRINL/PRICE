#ifndef GREEKS_H
#define GREEKS_H
#include "Option.h"
class Greeks
{
public:
    Greeks(Option& Option, unsigned long prec);
    double Delta(double centre, double ecart) const;
        double Theta(double centre, double ecart) const;
                double Gamma(double centre, double ecart) const;
                                double Vega(double centre, double ecart) const;
                                double Rho(double centre, double ecart) const;
private :
    Option& m_Option;
    unsigned long m_prec;

};


#endif // GREEKS_H
