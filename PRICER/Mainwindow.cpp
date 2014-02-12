#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Option.h"
#include "Genealeatoire.h"
#include "Time.h"
#include "MC.h"
#include "Greeks.h"
#include "StatGatherer.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <QtGui>
#include <QWidget>
#include <QPixmap>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :

  QMainWindow(parent),
  ui(new Ui::MainWindow),  prec(200), Spot(0), Strike(0), Expiry(0), Vol(0), r(0), lambda(0), m(0), vega2(0), StopMCType(10), NumberOfPaths(0), secondes(0), PO(0)
  {
  ui->setupUi(this);
  QWidget::setUpdatesEnabled(true);
  ui->statusBar->setWindowTitle("Pricer ++");

// Connextion des boutons //
connect(ui->OK, SIGNAL(clicked()), this, SLOT(update2()));
connect(ui->Greeks, SIGNAL(clicked()), this, SLOT(update3()));

connect(ui->PB, SIGNAL(clicked()), this, SLOT(AddSimuB()));
connect(ui->PL, SIGNAL(clicked()), this, SLOT(AddSimuL()));


}

////////////////////////////////////// RECUPERATION DES DONNES DE L'UTILISATEUR ////////////////////////////

double  MainWindow::edSpot()
{
    QString montexte = ui->eSpot->text();
    return montexte.toDouble();;
}

double  MainWindow::edStrike()
{
    QString montexte = ui->eStrike->text();
    return montexte.toDouble();;
}

double  MainWindow::edExpiry()
{
    QString montexte = ui->eExpiry->text();
    return montexte.toDouble();;
}

double  MainWindow::edVol()
{
    QString montexte = ui->eVol->text();
    return montexte.toDouble();;
}

double  MainWindow::edm()
{
    QString montexte = ui->em->text();
    return montexte.toDouble();;
}

double  MainWindow::edr()
{
    QString montexte = ui->er->text();
    return montexte.toDouble();;
}

double  MainWindow::edlambda()
{
    QString montexte = ui->elambda->text();
    return montexte.toDouble();;
}

double  MainWindow::edvega2()
{
    QString montexte = ui->evega2->text();
    return montexte.toDouble();;
}

bool  MainWindow::edMCStop()
{
    bool oun = ui->eite->isChecked();
    return oun;
}

bool  MainWindow::edPOC()
{
    bool oun = ui->eCal->isChecked();
    return oun;
}

unsigned long  MainWindow::edNumberOfPaths()
{
    QString montexte = ui->eNumberOfPaths->text();
    return montexte.toLong();;
}

int  MainWindow::edt()
{
    QString montexte = ui->esecondes->text();
    return montexte.toInt();;
}

void  MainWindow::update2()
{
    Spot=edSpot();
    Strike=edStrike();
    Expiry=edExpiry();
    Vol=edVol();
    r=edr();
    lambda=edlambda();
    m=edm();
    vega2=edvega2();
    if (edMCStop()==false)
        StopMCType=1;
    int TypeOption(0);
    if (edPOC()==true)
        TypeOption=1;
    NumberOfPaths=edNumberOfPaths();
    secondes=edt();
    PayOff* PO;
    if (TypeOption==1)
    {
    PO = new PayOffCall(Strike);
    }
    else
    {
    PO = new PayOffPut(Strike);
    };

    ui->Plot_PayOffB->clearGraphs();
    ui->Plot_PayOffL->clearGraphs();
    ui->Plot_SimuB->clearGraphs();
    ui->Plot_SimuL->clearGraphs();
    ui->Plot_ConvL->clearGraphs();
    ui->Plot_ConvB->clearGraphs();
    ui->RhoB->setText("-");
    ui->RhoL->setText("-");
    ui->VegaB->setText("-");
    ui->VegaL->setText("-");
    ui->GammaB->setText("-");
    ui->GammaL->setText("-");
    ui->DeltaB->setText("-");
    ui->DeltaL->setText("-");
    ui->ThetaB->setText("-");
    ui->ThetaL->setText("-");
    SetupPlotSimuB();
    SetupPlotSimuL();
    SetupPlotPayOffB();
    SetupPlotPayOffL();
    SetupPrices();

}


void  MainWindow::update3()
{
Greeksc();
}


// Destructeur de notre fenêtre.
MainWindow::~MainWindow()
{
  delete ui;
}

////////////////////////////////// GRAPHE 1 : GRAPHE SIMU BROWNIEN //////////////////////////////////////

void MainWindow::SetupPlotSimuB()
{

// Création de l'objet brownien

OptionB pSimuB(Strike, Expiry, Spot, Vol, r, *PO);

// Setup des caractéristiques du graphe //

  ui->Plot_SimuB->xAxis->setRange(0, Expiry, Qt::AlignLeft);
  ui->Plot_SimuB->yAxis->setRange(Spot, 5*Vol*Spot*sqrt(Expiry), Qt::AlignCenter);
  ui->Plot_SimuB->xAxis->setLabel("Temps (en années)");
  ui->Plot_SimuB->yAxis->setLabel("Cours");
  ui->Plot_SimuB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                   QCP::iSelectLegend | QCP::iSelectPlottables);
  ui->Plot_SimuB->addGraph();
  ui->Plot_SimuB->graph()->setPen(QPen(Qt::blue));
  ui->Plot_SimuB->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));

// Vecteurs du graphe //

  StatGatherer SimuB(pSimuB,prec,Expiry);
  QVector<double> x=SimuB.Axis();
  QVector<double> y=SimuB.SimuCoursB();

// Graphes //

  ui->Plot_SimuB->graph(0)->setData(x, y);
  ui->Plot_SimuB->axisRect()->setupFullAxesBox(true);
  ui->Plot_SimuB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
  ui->Plot_SimuB->replot();

}


////////////////////////////////// GRAPHE 2 : GRAPHE SIMU LEVY //////////////////////////////////////

void MainWindow::SetupPlotSimuL()
{

// Setup des caractéristiques du graphe //
 ui->Plot_SimuL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                 QCP::iSelectLegend | QCP::iSelectPlottables);
 ui->Plot_SimuL->xAxis->setRange(0, Expiry, Qt::AlignLeft);
 ui->Plot_SimuL->yAxis->setRange(Spot, 5*Vol*Spot*sqrt(Expiry), Qt::AlignCenter);
 ui->Plot_SimuL->xAxis->setLabel("Temps (en années)");
 ui->Plot_SimuL->yAxis->setLabel("Cours");
 ui->Plot_SimuL->addGraph();
 ui->Plot_SimuL->graph()->setPen(QPen(Qt::red));
 ui->Plot_SimuL->graph()->setBrush(QBrush(QColor(120, 120, 20, 20)));

// Vecteurs du graphe //

 OptionL pSimuL(Strike, Expiry, Spot, Vol, r, lambda, m, vega2, *PO);
 StatGatherer SimuL(pSimuL,prec,Expiry);
 QVector<double> x=SimuL.Axis();
 QVector<double> y=SimuL.SimuCoursB();

// Graphes //

   ui->Plot_SimuL->graph(0)->setData(x, y);
   ui->Plot_SimuL->axisRect()->setupFullAxesBox(true);
   ui->Plot_SimuL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
   ui->Plot_SimuL->replot();

}

////////////////////////////////// GRAPHE 3 : PAYOFF BROWNIEN //////////////////////////////////////

void MainWindow::SetupPlotPayOffB()
{

PayOff* PO;
if (TypeOption==1)
{
               PO = new PayOffCall(Strike);
}
else
{
PO = new PayOffPut(Strike);
};

// Objet brownien

OptionB pSimuB(Strike, Expiry, Spot, Vol, r, *PO);

// Setup des caractéristiques du graphe //

ui->Plot_PayOffB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                       QCP::iSelectLegend | QCP::iSelectPlottables);
ui->Plot_PayOffB->legend->setVisible(true);
ui->Plot_PayOffB->addGraph();
ui->Plot_PayOffB->graph()->setPen(QPen(Qt::blue));
ui->Plot_PayOffB->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
ui->Plot_PayOffB->addGraph();
QFont legendFont = font();
legendFont.setPointSize(10);
ui->Plot_PayOffB->legend->setFont(legendFont);
ui->Plot_PayOffB->legend->setSelectedFont(legendFont);
ui->Plot_PayOffB->legend->setSelectableParts(QCPLegend::spItems);
ui->Plot_PayOffB->xAxis->setRange(0, 2*Strike, Qt::AlignLeft);
ui->Plot_PayOffB->yAxis->setRange(0, Spot, Qt::AlignLeft);
ui->Plot_PayOffB->xAxis->setLabel("Spot Price");
ui->Plot_PayOffB->yAxis->setLabel("Prix de l'option");
QPen graphPen;
graphPen.setColor(QColor(51, 204, 0));
graphPen.setWidthF(2);
ui->Plot_PayOffB->graph()->setPen(graphPen);

// Vecteurs du graphe //

   StatGatherer GraphePO(pSimuB, prec, 2*Strike);
   QVector<double> x=GraphePO.Axis();
   QVector<double> y=GraphePO.GPO();
   QVector<double> z=GraphePO.GPOT();

// Graphes //

   ui->Plot_PayOffB->graph(0)->setData(x, y);
   ui->Plot_PayOffB->graph(0)->setName("Prix aujourd'hui");
   ui->Plot_PayOffB->graph(1)->setData(x, z);
   ui->Plot_PayOffB->graph(1)->setName("Prix à la maturité");
   ui->Plot_PayOffB->axisRect()->setupFullAxesBox(true);
   ui->Plot_PayOffB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
   ui->Plot_PayOffB->replot();
}


////////////////////////////////// GRAPHE 4 : PAYOFF LEVY //////////////////////////////////////

void MainWindow::SetupPlotPayOffL()
{

PayOff* PO;
if (TypeOption==1)
{
PO = new PayOffCall(Strike);
}
else
{
PO = new PayOffPut(Strike);
};


    // Objet de Levy

OptionL pSimuL(Strike, Expiry, Spot, Vol, r, lambda, m, vega2, *PO);

    // Setup des caractéristiques du graphe //

ui->Plot_PayOffL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                           QCP::iSelectLegend | QCP::iSelectPlottables);
ui->Plot_PayOffL->legend->setVisible(true);
QFont legendFont = font();
legendFont.setPointSize(10);
ui->Plot_PayOffL->legend->setFont(legendFont);
ui->Plot_PayOffL->legend->setSelectedFont(legendFont);
ui->Plot_PayOffL->legend->setSelectableParts(QCPLegend::spItems);
ui->Plot_PayOffL->xAxis->setRange(0, 2*Strike, Qt::AlignLeft);
ui->Plot_PayOffL->yAxis->setRange(0, Spot, Qt::AlignLeft);
ui->Plot_PayOffL->xAxis->setLabel("Spot Price");
ui->Plot_PayOffL->yAxis->setLabel("Prix de l'option");
ui->Plot_PayOffL->addGraph();
ui->Plot_PayOffL->graph()->setPen(QPen(Qt::red));
ui->Plot_PayOffL->graph()->setBrush(QBrush(QColor(120, 120, 20, 20)));
ui->Plot_PayOffL->addGraph();
QPen graphPen;
graphPen.setColor(QColor(51, 204, 0));
graphPen.setWidthF(2);
ui->Plot_PayOffL->graph()->setPen(graphPen);

    // Vecteurs du graphe //

StatGatherer GraphePO(pSimuL, prec, 2*Strike);
QVector<double> x=GraphePO.Axis();
QVector<double> y=GraphePO.GPO();
QVector<double> z=GraphePO.GPOT();//gPayOT(pSimuL,*PO, prec, Strike);

    // Graphes //

ui->Plot_PayOffL->graph(0)->setData(x, y);
ui->Plot_PayOffL->graph(0)->setName("Prix aujourd'hui");
ui->Plot_PayOffL->graph(1)->setData(x, z);
ui->Plot_PayOffL->graph(1)->setName("Prix à la maturité");
ui->Plot_PayOffL->axisRect()->setupFullAxesBox(true);
ui->Plot_PayOffL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
ui->Plot_PayOffL->replot();

}

void MainWindow::SetupPrices()
{
   // INITIALISATION DES VALEURS //

PayOff* PO;
if (TypeOption==1)
{
PO = new PayOffCall(Strike);
}
else
{
PO = new PayOffPut(Strike);
};

if (StopMCType==1)
    NumberOfPaths=1000000;


OptionB pSimuB(Strike, Expiry, Spot, Vol, r, *PO);
OptionL pSimuL(Strike, Expiry, Spot, Vol, r, lambda, m, vega2, *PO);

    MC maMC;
QVector <double> PrixBV=maMC.PrixA(NumberOfPaths, pSimuB);
QVector <double> PrixLV=maMC.PrixA(NumberOfPaths, pSimuL);
double PrixB;

if (StopMCType==1)
    PrixB= maMC.PrixT(secondes, pSimuB);
else
    PrixB=PrixBV[NumberOfPaths-1];

double PrixL;
if (StopMCType==1)
    PrixL= maMC.PrixT(secondes, pSimuL);
else
    PrixL=PrixLV[NumberOfPaths-1];

ui->RB->setNum(PrixB);
ui->RL->setNum(PrixL);
ui->lSpot->setNum(Spot);
ui->lExpiry->setNum(Expiry);
ui->lStrike->setNum(Strike);
ui->lsigma2->setNum(Vol);
ui->llambda->setNum(lambda);
ui->lm->setNum(m);
ui->tr->setNum(r);
ui->lvega2->setNum(vega2);
ui->lOptionType->setText("Européenne");
if (TypeOption==1)
ui->lCoP->setText("Call");
else ui->lCoP->setText("Put");

QString s = QString::number(NumberOfPaths);

if (StopMCType==0)
{
ui->SMC->setText("Nombre d'itérations");
ui->lNumberOfPaths->setText(s);
ui->lsecondes->setText("-");
}
else
{
    ui->SMC->setText("Temps de calcul");
    ui->lsecondes->setNum(secondes);
    ui->lNumberOfPaths->setText("-");
}

ui->Plot_ConvB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);
ui->Plot_ConvB->xAxis->setRange(0, NumberOfPaths, Qt::AlignLeft);
ui->Plot_ConvB->yAxis->setRange(PrixB, 0.9, Qt::AlignCenter);
ui->Plot_ConvB->xAxis->setLabel("Nombre d'itérations");
ui->Plot_ConvB->yAxis->setLabel("Estimation du Pay-Off");
ui->Plot_ConvB->addGraph();
QPen graphPen;
graphPen.setColor(QColor(0, 153, 253));
graphPen.setWidthF(1);
ui->Plot_ConvB->graph()->setPen(graphPen);

// Vecteurs du graphe //
StatGatherer GraphePO(pSimuB, NumberOfPaths, NumberOfPaths);
QVector<double> x=GraphePO.Axis();
QVector<double> y=PrixBV;

// Graphes //

ui->Plot_ConvB->graph(0)->setData(x, y);
ui->Plot_ConvB->axisRect()->setupFullAxesBox(true);
ui->Plot_ConvB->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
ui->Plot_ConvB->replot();



ui->Plot_ConvL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);
ui->Plot_ConvL->xAxis->setRange(0, NumberOfPaths, Qt::AlignLeft);
ui->Plot_ConvL->yAxis->setRange(PrixL, 0.9, Qt::AlignCenter);
ui->Plot_ConvL->xAxis->setLabel("Nombre d'itérations");
ui->Plot_ConvL->yAxis->setLabel("Estimation du Pay-Off");
ui->Plot_ConvL->addGraph();
QPen graphPen2;
graphPen2.setColor(QColor(255, 0, 0));
graphPen2.setWidthF(1);
ui->Plot_ConvL->graph()->setPen(graphPen2);

// Vecteurs du graphe //
StatGatherer GraphePrixL(pSimuL, NumberOfPaths, NumberOfPaths);
QVector<double> x2=GraphePrixL.Axis();
QVector<double> y2=PrixLV;

// Graphes //

ui->Plot_ConvL->graph(0)->setData(x2, y2);
ui->Plot_ConvL->axisRect()->setupFullAxesBox(true);
ui->Plot_ConvL->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
ui->Plot_ConvL->replot();


double VarEmpBS(0);
for (unsigned long i(0);i<NumberOfPaths-1;++i)
{
    VarEmpBS+=(PrixBV[i]-PrixB)*(PrixBV[i]-PrixB);
}
double VarEmpB(VarEmpBS/(NumberOfPaths-1));
ui->VarEmpB->setNum(sqrt(VarEmpB));


double VarEmpLS(0);
for (unsigned long i(0);i<NumberOfPaths-1;++i)
{
    VarEmpLS+=(PrixLV[i]-PrixL)*(PrixLV[i]-PrixL);
}
double VarEmpL(VarEmpLS/(NumberOfPaths-1));
ui->VarEmpL->setNum(sqrt(VarEmpL));


}

void MainWindow :: Greeksc()

{
    PayOff* PO;
    if (TypeOption==1)
    {
    PO = new PayOffCall(Strike);
    }
    else
    {
    PO = new PayOffPut(Strike);
    };

OptionL pSimuL(Strike, Expiry, Spot, Vol, r, lambda, m, vega2, *PO);
OptionB pSimuB(Strike, Expiry, Spot, Vol, r, *PO);
class Greeks GrecquesB(pSimuB,1000000);

double deltaB=GrecquesB.Delta(Spot, Spot*0.02);
ui->DeltaB->setNum(deltaB);

double thetaB=GrecquesB.Theta(Expiry, Expiry*0.10);
ui->ThetaB->setNum(thetaB);

double gammaB=GrecquesB.Gamma(Spot,Spot*0.20);
ui->GammaB->setNum(gammaB);

double VegaB=GrecquesB.Vega(Vol,Vol*0.05);
ui->VegaB->setNum(VegaB);

double RhoB=GrecquesB.Rho(r,r*0.10);
ui->RhoB->setNum(RhoB);

class Greeks GrecquesL(pSimuL,1000000);
double deltaL=GrecquesL.Delta(Spot, Spot*0.02);
ui->DeltaL->setNum(deltaL);

double thetaL=GrecquesL.Theta(Expiry, Expiry*0.10);
ui->ThetaL->setNum(thetaL);

double gammaL=GrecquesL.Gamma(Spot,Spot*0.20);
ui->GammaL->setNum(gammaL);

double VegaL=GrecquesL.Vega(Vol,Vol*0.01);
ui->VegaL->setNum(VegaL);

double RhoL=GrecquesL.Rho(r,r*0.20);
ui->RhoL->setNum(RhoL);
}

////////////////////////////////// AJOUTER SIMULATIONS DE COURS //////////////////////////////////////

void MainWindow::AddSimuB()
{

OptionB pSimuB(Strike, Expiry, Spot, Vol, r, *PO);

StatGatherer SimuB(pSimuB,prec,Expiry);
QVector<double> x=SimuB.Axis();
QVector<double> y=SimuB.SimuCoursB();


// Setup des caractéristiques du graphe //

ui->Plot_SimuB->addGraph();
ui->Plot_SimuB->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));

ui->Plot_SimuB->graph()->setData(x, y);
QPen graphPen;
graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
ui->Plot_SimuB->graph()->setPen(graphPen);
ui->Plot_SimuB->replot();
}


void MainWindow::AddSimuL()
{

OptionL pSimuL(Strike, Expiry, Spot, Vol, r, lambda, m, vega2, *PO);
StatGatherer SimuL(pSimuL,prec,Expiry);
QVector<double> x=SimuL.Axis();
QVector<double> y=SimuL.SimuCoursB();

ui->Plot_SimuL->addGraph();
ui->Plot_SimuL->graph()->setBrush(QBrush(QColor(225, 102, 102, 40)));
ui->Plot_SimuL->graph()->setData(x, y);
QPen graphPen;
graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
ui->Plot_SimuL->graph()->setPen(graphPen);
ui->Plot_SimuL->replot();
}
