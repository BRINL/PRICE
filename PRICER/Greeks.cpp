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
    Pav=maMC.PrixAc(m_prec,m_Option,av, m_Option.getExpiry()) ;
    Pap=maMC.PrixAc(m_prec,m_Option,ap, m_Option.getExpiry());
    return (Pap-Pav)/(ap-av);
}

double Greeks :: Theta(double centre, double ecart) const
{
    double av(centre-ecart);
    double ap(centre+ecart) ;
    MC maMC;
    double Pav(0);
    double Pap(0);
    Pap=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), av) ;
    Pav=maMC.PrixAc(m_prec,m_Option,m_Option.getSpot(), ap);
    return (Pap-Pav)/(ap-av);
}
