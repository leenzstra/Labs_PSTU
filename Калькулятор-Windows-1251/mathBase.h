#pragma once
#include "brackets.h"
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace std;

string sx1, sx2;      //корни 
string disc;          //дискриминант
string checkEquation = "1234567890-+*/.()"; //проверка на ошибочные символы
string ErrorCheck;      //тип ошибки

bool check(System::String^ s) //проверка на ошибки
{
    std::string equation = msclr::interop::marshal_as<std::string>(s);  //полученный коэф.
       
    for (size_t i = 0; i < equation.length(); i++)  //проверка на ошибочный символ
    {
        char a = equation[i];
        bool yes = false;
        for (size_t j = 0; j < checkEquation.length(); j++)
            if (a == checkEquation[j])  
                yes = true;
        if (!yes)       //если 1+ символов в вводе не подошли
        {
            ErrorCheck = "Запрещенный символ";  //то выводим ошибку
            return false;
        }
        if (i != equation.length() - 1)
        {
            if ((equation[i] == '-' || equation[i] == '+') && (equation[i + 1] == '-' || equation[i + 1] == '+'))
            {
                ErrorCheck = "Проверьте знаки";
                return false;
            }
        }
    }

    eval(equation);     //решаем выражение
    if (ErrorB != "")   //если ошибки есть
    {
        ErrorCheck = ErrorB;    //то выводим
        return false;
    }

    return true;    //если нет ни 1 ошибки
}

void eraser(string &s)
{//число всегда типа: 100.0 поэтому нужные 0 не удаляются
    if (s[s.size() - 1] == '0') //если последний символ строки = 0
        for (size_t i = s.size() - 1; s[i] == '0'; i--) //идем с конца и удаляем нули
            s.erase(i, 1);

    if (s[s.size() - 1] == '.')     //удаление точки
        s.erase(s.size() - 1, 1);

    if (s == "-0")      //если -0, то ставим 0
        s = "0";
}

int solver(double a, double b, double c)
{
    if (a == 0)             //если уравнение не квадратное
        return -1;          //то выходим из функции
    if (b == 0 && c == 0)   //если коэф. B и C = 0, то x = 0
    {
        sx1 = "0"; sx2 = "0"; disc = "0";
        return -2;
    }
    double D = (b * b) - (4 * a * c);   //считаем дискриминант
    double x1, x2;
    disc = to_string(D);        //конвертируем в строку
    eraser(disc);               //и удаляем незначащие нули

    if (D < 0)
    {
        string sx1_1;
        double x1_1;

        x1_1 = (-b) / (2 * a);          //считаем первую часть корней
        x1 = -1*(sqrt(-1 * D)) / (2 * a);   //вторые части корней (мнимые)
        x2 = -1*(sqrt(-1 * D)) / (2 * a);
        if (x1 < 0)             //убираем все знаки 
        {
            x1 *= -1; x2 *= -1;
        }
        sx1_1 = to_string(x1_1);    //конвертируем в строку
        sx1 = to_string(x1);        
        sx2 = to_string(x2);
        
        eraser(sx1_1);              //и удаляем незначащие нули
        eraser(sx1);
        eraser(sx2);
        
        sx1 = sx1_1 + "+" + sx1 + "i";  //делаем полный ответ
        sx2 = sx1_1 + "-" + sx2 + "i";
    }
    else if (D == 0)            
    {
         x1 = -b / (2 * a);
         x2 = -b / (2 * a);
         sx1 = to_string(x1);
         sx2 = to_string(x2);
         eraser(sx1);
         eraser(sx2);
    }
    else // D > 0
    {
         x1 = (-b + sqrt(D)) / (2 * a);
         x2 = (-b - sqrt(D)) / (2 * a);
         sx1 = to_string(x1);
         sx2 = to_string(x2);
         eraser(sx1);
         eraser(sx2);

    }
    return 0;
}
