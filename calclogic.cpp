#include "calclogic.h"
#include "math.h"
#define PI 3.14159265


using namespace std;
//процедура проверяющая является ли символ числом
bool is_num(char x){
    string checker = "-0123456789.";
    if (checker.find(x)!=-1) return true;
    return false;
}
//процедура, откидывающая незначащие нули
string znach_nul(string s){
    while (s.rfind("0")!=-1){
        if (s.rfind("0")==s.size()-1)
            s.erase(s.rfind("0"),1);
        else
            return s;

    }
    if (s[s.size()-1]=='.')
        s.erase(s.size()-1,1);
    return s;
}
//процедура обработки операций +*/
string mat_operation(string x,string com){
    string s = "";
    int i;
    float c,d;
    i = 1;
    s="";
    int a = x.find(com);
    while((a-i>=0)&&(is_num(x[a-i]))){
        s=x[a-i]+s;
        i++;
    }
    c = stof(s);
    x.erase(a-s.size(),s.size());
    a = x.find(com);
    i=1;
    s="";
    while((a+i!=x.size())&&(is_num(x[a+i]))){
        s+=x[a+i];
        i++;
    }
    d = stof(s);
    x.erase(a+1,s.size());
    if (com =="*"){c*=d;}
    if (com =="/"){c/=d;}
    if (com =="+"){c+=d;}
    s = to_string(c);
    x.erase(a,1);
    x.insert(a,s);
    return x;
}
//процедура извлеения значения из скобок
string scobs(string x,unsigned a){

    unsigned os,cs,i;
    os = 1;
    cs = 0;
    i =1;
    while (os!=cs){
        if (x[a+i]=='(')
            os++;
        if (x[a+i]==')')
            cs++;
        i++;
    }
    return x.substr(a,i);
}

//Основаня процедура обработки строки
string CalcLogic::calculation(string a){
    string x = a;
    string s;
    int k,pos;
    //проверяем наличие логарифмов
    //Если есть вычисляем их
    while (x.find("ln")!=-1){
        pos = x.find("ln");
        s = scobs(x,(pos+3));
        x.erase(pos,s.size()+3);
        s = calculation(s);
        s = to_string(log(stof(s)));
        x.insert(pos,s);
    }
    //проверяем начличие синсов
    //Вычисляем их в градусах
    while (x.find("sin")!=-1){
        pos = x.find("sin");
        s = scobs(x,(pos+4));
        x.erase(pos,s.size()+4);
        s = calculation(s);
        s = to_string(sin(stof(s))*PI/180);
        x.insert(pos,s);
    }
    //проверяем начличие косинусов
    //Вычисляем их в градусах
    while (x.find("cos")!=-1){
        pos = x.find("cos");
        s = scobs(x,(pos+4));
        x.erase(pos,s.size()+4);
        s = calculation(s);
        s = to_string(cos(stof(s))*PI/180);
        x.insert(pos,s);
    }
    //проверяем начличие тангенсов
    //Вычисляем их в градусах
    while (x.find("tg")!=-1){
        pos = x.find("tg");
        s = scobs(x,(pos+3));
        x.erase(pos,s.size()+3);
        s = calculation(s);
        s = to_string(tan(stof(s))*PI/180);
        x.insert(pos,s);
    }
    //проверяем начличие экспонент
    //Вычисляем их
    while (x.find("exp")!=-1){
        pos = x.find("exp");
        s = scobs(x,(pos+4));
        x.erase(pos,s.size()+4);
        s = calculation(s);
        s = to_string(exp(stof(s)));
        x.insert(pos,s);
    }
    //проверяем начличие скобок
    //Вычисляем значения внутри
    while (x.find("(")!=-1){
        pos = x.find("(");
        if ((pos==0)||(x[pos-1]!='^')){
            s = scobs(x,(pos+1));
            x.erase(pos,s.size()+1);
            s = calculation(s);
            s = to_string(stof(s));
            x.insert(pos,s);
        }else{
            x.erase(pos,1);
            x.insert(pos,"s");
        }
    }
    //проверяем начличие степеней
    //Вычисляем их
    while (x.find("^")!=-1){
        pos = x.find("^");
        s = scobs(x,(pos+2));

        s = calculation(s);
        unsigned i = 1;
        string s1 = "";
        while((pos-i>=0)&&(is_num(x[pos-i]))){
            s1=x[pos-i]+s1;
            i++;
        }

        x.erase(pos-s1.size(),s.size()+2+s1.size());
        s = to_string(pow(stof(s1),stof(s)));
        x.insert(pos-s1.size(),s);
    }
    //Добавить + перед каждым минусом, что бы избежать обработки операции вычитания
    while (x.find("-")!=-1){
        k = x.find("-");
        x.erase(k,1);
        x.insert(k,"m");
        x.insert(k,"+");
    }
    while (x.find("m")!=-1){
        k = x.find("m");
        x.erase(k,1);
        x.insert(k,"-");
    }
    //Выполняем деление и умножение
    while ((x.find("*")!=-1)||(x.find("/")!=-1)){
        if (x.find("*")!=-1){
            if (x.find("/")!=-1){
                if ((x.find("*")<x.find("/")))x = mat_operation(x,"*");
                else x = mat_operation(x,"/");
            }
            else x = mat_operation(x,"*");
        }else x = mat_operation(x,"/");
    }
    //Выполняем суммирование
    while (x.find("+")!=-1){
        x = mat_operation(x,"+");
    }
    //Откидываем незначащие нули
    x = znach_nul(x);
    //Возвращаем строку
    return x;
}
