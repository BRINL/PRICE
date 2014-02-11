#include "MC.h"
#include <QVector>
#include "Option.h"

MC::MC() : i(0)
{   
}


QVector <double> MC::PrixA(unsigned long NumberOfPaths, Option& Simu)
{
    QVector <double> PrixAV(NumberOfPaths);
    double runningSum(0);
    unsigned long i(0);
    while (i<NumberOfPaths-1)
 {
     i+=1;
     runningSum+=Simu.getPayOff(Simu);
     PrixAV[i]=(runningSum/i)*exp(-Simu.getExpiry()*Simu.getr());
 }
    return PrixAV;
 }


double MC::PrixT(int secondes, Option& Simu)
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
        runningSum+=Simu.getPayOff(Simu);
        texec=difftime(tend,tbegin);    // tend-tbegin (resultat en secondes)
    }
    double mean = (runningSum/k)*exp(-Simu.getExpiry()*Simu.getr());
    return mean;
}

double MC::PrixAc(unsigned long NumberOfPaths, Option& Simu, double Spot, double Expiry)
{
    double runningSum(0);
    for(int i=1;i<NumberOfPaths;i++)
    {
        runningSum+=Simu.getPayOffg(Simu, Spot, Expiry);
    }
    double mean = runningSum/NumberOfPaths;
    double resultat=mean*exp(-(Simu.getExpiry()*Simu.getr()));
    return resultat;
}

