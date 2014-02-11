#include "Simu.h"
#include "Option.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <QVector>
#include "MC.h"

using namespace std;

////////////////////////////////// SIMU DE COURS //////////////////////////////////////

QVector<double> Simul(Option& pSimu, int prec)
{
QVector<double> Simulr(prec);
double rec(pSimu.getSpot());
double pas=(pSimu.getExpiry()/prec);
double tempspas=(pas);
for (int j=0;j<prec;++j)
{
    tempspas+=pas;
    rec=pSimu.Simu(rec,pas);
    Simulr[j]=rec;
}
    return Simulr;
}

////////////////////////////////// SIMU POUR DIFFERENTS SPOT //////////////////////////////////////
/*

QVector<double> gPayO(Option& pMC, PayOff& PO, int prec, double Strike, double Expiry)
{
    QVector<double> gPayOr(prec);
    double POt;
    double pas=(2*Strike)/prec;
    double axe(0);
    for (int j=0;j<prec;j++)
    {
        MC maMC;
        axe+=pas;
        POt=maMC.PrixAc(10000,pMC, );
        gPayOr[j]=POt;
    }
    return gPayOr;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

QVector<double> gPayOT(Option& pMC, PayOff& PO, int prec, double Strike)
{
     double POT;
     QVector<double> gPayOr(prec);
     double pas=(2*Strike)/prec;
     double axe(0);
     for (int j=0;j<prec;j++)
     {
         axe+=pas;
         POT=PO(axe);
         gPayOr[j]=POT;
     }
     return gPayOr;
}

