#ifndef CALCCONTROL_H
#define CALCCONTROL_H
#include "mainwindow.h"


class CalcControl
{
private:
    QString lasts;//проля для истории вычислений
    QString s;//поле рабочей строки


public:
    //Конструктор
    CalcControl();
    //Удаление
    QString del();
    //обработка ввода
    QString input(QString x);
    //Вызов логики
    QString tologic();
    //получение строки истории вычислений
    QString get_last_s()const;
    //получение рабочей строки
    QString get_s()const;
    //задание значения в строку памяти
    void set_last_s(QString x);
};

#endif // CALCCONTROL_H
