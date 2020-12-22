#ifndef CALCCONTROL_H
#define CALCCONTROL_H
#include "mainwindow.h"


class CalcControl
{
private:
    QString lasts;
    QString s;


public:
    CalcControl();
    QString del();
    QString input(QString x);
    QString tologic();
    QString get_last_s()const;
    QString get_s()const;
    void set_last_s(QString x);
};

#endif // CALCCONTROL_H
