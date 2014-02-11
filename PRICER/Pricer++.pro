#-------------------------------------------------
#
# Project created by QtCreator 2013-07-25T20:43:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PRICER++
TEMPLATE = app


SOURCES += main.cpp\
    PayOff.cpp \
    Genealeatoire.cpp \
    Simu.cpp \
    Mainwindow.cpp \
    qcustomplot.cpp \
    MC.cpp \
    Option.cpp \
    StatGatherer.cpp \
    Greeks.cpp

HEADERS  += \
    Genealeatoire.h \
    Simu.h \
    Mainwindow.h \
    qcustomplot.h \
    MC.h \
    PayOff.h \
    Option.h \
    StatGatherer.h \
    Greeks.h

FORMS    += mainwindow.ui
