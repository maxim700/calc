#include "calccontrol.h"
#include "calclogic.h"

CalcControl::CalcControl()
{
    this->lasts = "";
    this->s = "";
}
QString CalcControl::del(){
    this->s = this->s.remove(this->s.length()-1,1);
    return this->s;
}
QString CalcControl::input(QString x){
    this->s += x;
    return this->s;
}
QString CalcControl::tologic(){
   this->s = CalcLogic::calculation(this->s);
   return this->s;
}
QString CalcControl::get_last_s()const{
    return this->lasts;

}
QString CalcControl::get_s()const{
    return this->s;
}
void CalcControl::set_last_s(QString x){
    this->lasts=x;
}
