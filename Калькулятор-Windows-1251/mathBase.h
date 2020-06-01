#pragma once
#include "brackets.h"
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace std;

string sx1, sx2;      //����� 
string disc;          //������������
string checkEquation = "1234567890-+*/.()"; //�������� �� ��������� �������
string ErrorCheck;      //��� ������

bool check(System::String^ s) //�������� �� ������
{
    std::string equation = msclr::interop::marshal_as<std::string>(s);  //���������� ����.
       
    for (size_t i = 0; i < equation.length(); i++)  //�������� �� ��������� ������
    {
        char a = equation[i];
        bool yes = false;
        for (size_t j = 0; j < checkEquation.length(); j++)
            if (a == checkEquation[j])  
                yes = true;
        if (!yes)       //���� 1+ �������� � ����� �� �������
        {
            ErrorCheck = "����������� ������";  //�� ������� ������
            return false;
        }
        if (i != equation.length() - 1)
        {
            if ((equation[i] == '-' || equation[i] == '+') && (equation[i + 1] == '-' || equation[i + 1] == '+'))
            {
                ErrorCheck = "��������� �����";
                return false;
            }
        }
    }

    eval(equation);     //������ ���������
    if (ErrorB != "")   //���� ������ ����
    {
        ErrorCheck = ErrorB;    //�� �������
        return false;
    }

    return true;    //���� ��� �� 1 ������
}

void eraser(string &s)
{//����� ������ ����: 100.0 ������� ������ 0 �� ���������
    if (s[s.size() - 1] == '0') //���� ��������� ������ ������ = 0
        for (size_t i = s.size() - 1; s[i] == '0'; i--) //���� � ����� � ������� ����
            s.erase(i, 1);

    if (s[s.size() - 1] == '.')     //�������� �����
        s.erase(s.size() - 1, 1);

    if (s == "-0")      //���� -0, �� ������ 0
        s = "0";
}

int solver(double a, double b, double c)
{
    if (a == 0)             //���� ��������� �� ����������
        return -1;          //�� ������� �� �������
    if (b == 0 && c == 0)   //���� ����. B � C = 0, �� x = 0
    {
        sx1 = "0"; sx2 = "0"; disc = "0";
        return -2;
    }
    double D = (b * b) - (4 * a * c);   //������� ������������
    double x1, x2;
    disc = to_string(D);        //������������ � ������
    eraser(disc);               //� ������� ���������� ����

    if (D < 0)
    {
        string sx1_1;
        double x1_1;

        x1_1 = (-b) / (2 * a);          //������� ������ ����� ������
        x1 = -1*(sqrt(-1 * D)) / (2 * a);   //������ ����� ������ (������)
        x2 = -1*(sqrt(-1 * D)) / (2 * a);
        if (x1 < 0)             //������� ��� ����� 
        {
            x1 *= -1; x2 *= -1;
        }
        sx1_1 = to_string(x1_1);    //������������ � ������
        sx1 = to_string(x1);        
        sx2 = to_string(x2);
        
        eraser(sx1_1);              //� ������� ���������� ����
        eraser(sx1);
        eraser(sx2);
        
        sx1 = sx1_1 + "+" + sx1 + "i";  //������ ������ �����
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
