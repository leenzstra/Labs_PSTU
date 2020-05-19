#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

double eval(std::string s); //������� ������ � ������ char � �������
double number(char*);       //���������� ����� � ��� �����
double expression(char*);   //������ ���������� ����������
double term(char*);         //�������� * � /
double brackets(char*);     //���������� �������� � �������

std::string ErrorB;     //������
int symb;               //������� ��������

double eval(std::string s)
{
    ErrorB = "";
    symb = 0;
    char* str = new char[s.length()];
    for (size_t i = 0; i < s.length(); i++)
        str[i] = s[i];
    return expression(str);
}

double number(char* str)
{
    double result = 0;
    double div = 10;
    int sign = 1;

    if (str[symb] == '-')
    {
        sign = -1;          //��������� ����� �����
        symb++;
    }

    while (str[symb] >= '0' && str[symb] <= '9')
    {
        result = result * 10 + (str[symb] - '0');   //���������� ����� �� �������
        symb++;
    }

    if (str[symb] == '.')
    {
        symb++;
        while (str[symb] >= '0' && str[symb] <= '9')    //���������� ��������
        {
            result = result + (str[symb] - '0') / div;
            div *= 10;
            symb++;
        }
    }
    return sign * result;
}

double expression(char* str)
{
    double result = term(str);

    while (str[symb] == '+' || str[symb] == '-')
    {
        if (str[symb] == '+')
        {
            symb++;
            result += term(str);
        }

        if (str[symb] == '-')
        {
            symb++;
            result -= term(str);
            break;
        }
    }
    return result;
}

double term(char* str)
{
    double result = brackets(str);
    double div;

    while (str[symb] == '*' || str[symb] == '/')
    {
        if (str[symb] == '*')
        {
            symb++;
            result *= brackets(str);
        }
        if (str[symb] == '/')
        {
            symb++;
            div = brackets(str);
            if (div != 0)
                result /= div;
            else
            {
                ErrorB = "������� �� 0";
                return -1;
            }
        }
    }
    return result;
}

double brackets(char* str)
{
    double result;
    int sign = 1;

    if (str[symb] == '-')
    {
        sign = -1;
        symb++;
    }
    if (str[symb] == '(')
    {
        symb++;
        result = expression(str);
        if (str[symb] != ')')
        {
            ErrorB = "��������� ������";
            return -1;
        }
        symb++;
    }
    else
        result = number(str);
    return sign * result;
}