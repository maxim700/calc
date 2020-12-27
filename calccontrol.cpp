#include "calccontrol.h"
#include "calclogic.h"

//конструктор
CalcControl::CalcControl()
{

    this->lasts = "";
    this->s = "";
}
//Удаление
QString CalcControl::del(){
    this->s = this->s.remove(this->s.length()-1,1);
    return this->s;
}
//Обработка входящих данных
QString CalcControl::input(QString x){
    this->s += x;
    return this->s;
}
//Вызов логики калькулятора
QString CalcControl::tologic(){
   this->s = QString::fromStdString(CalcLogic::calculation(this->s.toStdString()));
   return this->s;
}
//получение истории
QString CalcControl::get_last_s()const{
    return this->lasts;

}
//получение рабоччей строки
QString CalcControl::get_s()const{
    return this->s;
}
//Задание истории
void CalcControl::set_last_s(QString x){
    this->lasts=x;
}
