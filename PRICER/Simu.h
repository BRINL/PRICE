#ifndef SIMU_H
#define SIMU_H

#include <iostream>
#include <vector>
#include "Option.h"
#include <QVector>


QVector<double> Simul(Option& MonTest, int prec);
/*
QVector<double> gPayO(Option& MonTest, PayOff& PO, int prec, double Strike, double Expiry);
QVector<double> gPayOT(Option& pMC, PayOff& PO, int prec, double Strike);
*/
#endif // SIMU_H
