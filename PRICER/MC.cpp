#include "MC.h"
#include <QVector>
#include "Option.h"
using namespace std;

MC::MC() : i(0)
{   
}


QVector <double> MC::PrixA(unsigned long NumberOfPaths, Option& Option)
{
    QVector <double> PrixAV(NumberOfPaths);
    double runningSum(0);
    unsigned long i(0);
    while (i<NumberOfPaths-1)
 {
     QVector <double> A=Option.getPayOff(Option);
        i+=1;
     runningSum+=0.5*(A[0]+A[1]);
     PrixAV[i]=(runningSum/i)*exp(-Option.getExpiry()*Option.getr());
 }
    return PrixAV;
 }



double MC::PrixT(int secondes, Option& Option)
{
    time_t tbegin,tend;
    unsigned long k=0;
    double texec=0.;
    double runningSum(0);
    tbegin=time(NULL);              // Date du debut
    while (texec<secondes)
    {
        tend=time(NULL);                // Date de fin
        k+=1;
        QVector <double> A=Option.getPayOff(Option);
        runningSum+=0.5*(A[0]+A[1]);
        texec=difftime(tend,tbegin); // tend-tbegin (resultat en secondes)
    }
    double resultat=(runningSum/k)*exp(-Option.getExpiry()*Option.getr());
    return resultat;
}

double MC::PrixAc(unsigned long NumberOfPaths, Option& Simu, double Spot, double Expiry, double r, double sigma)
{
    double runningSum(0);
    for(int i=1;i<NumberOfPaths;i++)
    {
        runningSum+=Simu.getPayOffg(Simu, Spot, Expiry, r, sigma);
    }
    double mean = runningSum/NumberOfPaths;
    double resultat=mean*exp(-(Expiry*r));
    return resultat;
}

