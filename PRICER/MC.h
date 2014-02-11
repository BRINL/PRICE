#include "Option.h"
#include <QVector>
#ifndef MC_H
#define MC_H

class MC
{
public:
    MC();
    QVector <double> PrixA(unsigned long NumberOfPaths, Option& Simu);
    double PrixT(int secondes, Option& Simu);
    double PrixAc(unsigned long NumberOfPaths, Option& Simu, double Spot, double Expiry);
private :
    int i;

};


#endif // MC_H
