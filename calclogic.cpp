#include "calclogic.h"

bool is_num(QCharRef x){
    QString checker = "-0123456789.";
    if (checker.indexOf(x)>-1) return true;
    return false;
}

QString mat_operation(QString x,QString com){
    QString s = "";
    int i;
    float c,d;
    i = 1;
    s="";
    int a = x.indexOf(com);

    while((a-i>=0)&&(is_num(x[a-i]))){
        s+=x[a-i];
        i++;
    }
    c = s.toFloat();
    x.remove(a-s.length(),s.length());
    a = x.indexOf(com);
    i=1;
    s="";
    while((a-i<x.length())&&(is_num(x[a+i]))){
        s+=x[a+i];
        i++;
    }
    d = s.toFloat();
    x.remove(a+1,s.length());
    if (com =="*"){c*=d;}
    if (com =="/"){c/=d;}
    if (com =="+"){c+=d;}
    s.setNum(c);
    x.remove(a,1);
    x.insert(a,s);
    return x;
}


QString CalcLogic::calculation(QString a){
    QString x = a;
    int k;
    //Добавить + gthtl перед каждым минусом
    while (x.indexOf("-")>-1){
        k = x.indexOf("-");
        x.remove(k,1);
        x.insert(k,"m");
        x.insert(k,"+");
    }
    while (x.indexOf("m")>-1){
        k = x.indexOf("m");
        x.remove(k,1);
        x.insert(k,"-");
    }
    while ((x.indexOf("*")>-1)||(x.indexOf("/")>-1)){
        if (x.indexOf("*")>-1){
            if (x.indexOf("/")>-1){
                if ((x.indexOf("*")<x.indexOf("/")))x = mat_operation(x,"*");
                else x = mat_operation(x,"/");
            }
            else x = mat_operation(x,"*");
        }else x = mat_operation(x,"/");
    }
    while (x.indexOf("+")>-1){
        x = mat_operation(x,"+");
    }
    return x;
}
