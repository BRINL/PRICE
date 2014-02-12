#include "Greeks.h"
#include "Option.h"
#include "MC.h"


Greeks::Greeks(Option& MonOption, unsigned long prec) : m_Option(MonOption), m_prec(prec)
{
}
double Greeks :: Delta(double centre, double ecart) const
{
    double av(centre-ecart);
    double ap(centre+ecart) ;
    MC maMC;
    double Pav(0);
    double Pap(0);
    Pav=maMC.PrixAc(m_prec,m_Option,av, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma()) ;
    Pap=maMC.PrixAc(m_prec,m_Option,ap, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma());
    return (Pap-Pav)/(ap-av);
}

double Greeks :: Theta(double centre, double ecart) const
{
    double av(centre-ecart);
    double ap(centre+ecart) ;
    MC maMC;
    double Pav(0);
    double Pap(0);
    Pav=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), av, m_Option.getr(), m_Option.getSigma()) ;
    Pap=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), ap, m_Option.getr(), m_Option.getSigma());
    return -(Pap-Pav)/(ap-av);
}

double Greeks :: Gamma(double centre, double ecart) const
{
    double av2(centre-2*ecart);
    double av(centre-ecart);
    double ap(centre+ecart);
    double ap2(centre+2*ecart) ;
    MC maMC;
    double Pav2(0);
    double Pav(0);
    double Pap(0);
    double Pap2(0);
    Pap2=maMC.PrixAc(m_prec,m_Option, av2, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma()) ;
    Pap=maMC.PrixAc(m_prec,m_Option,av, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma()) ;
    Pap=maMC.PrixAc(m_prec,m_Option, ap, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma());
    Pav2=maMC.PrixAc(m_prec,m_Option, ap2, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma());
    return -(((Pav-Pav2)/(av-av2))-((Pap2-Pap)/(ap2-ap)))/(3*ecart);
}

double Greeks :: Vega(double centre, double ecart) const
{
    double av(centre-ecart);
    double ap(centre+ecart) ;
    MC maMC;
    double Pav(0);
    double Pap(0);
    Pav=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), m_Option.getExpiry(), m_Option.getr(), av) ;
    Pap=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), m_Option.getExpiry(), m_Option.getr(), ap);
    return (Pap-Pav)/(ap-av);
}


double Greeks :: Rho(double centre, double ecart) const
{
    double av(centre-ecart);
    double ap(centre+ecart) ;
    MC maMC;
    double Pav(0);
    double Pap(0);
    Pav=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), m_Option.getExpiry(), av, m_Option.getSigma()) ;
    Pap=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), m_Option.getExpiry(), ap, m_Option.getSigma());
    return (Pap-Pav)/(ap-av);
}
