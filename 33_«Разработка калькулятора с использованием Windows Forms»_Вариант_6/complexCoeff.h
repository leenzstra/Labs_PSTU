#include <string>
#include <msclr/marshal_cppstd.h>
#include <complex>
using namespace std;

complex<double> ACompl;		//коэф А
complex<double> BCompl;		//коэф В
complex<double> CCompl;		//коэф С
complex<double> Discr;		//дискриминант

string checkEquationCompl = "1234567890-+.i()";	//проверка на ошибки
string ErrorCheckCompl;		//ошибка

string sx1RCompl;		//действ. часть 1 корня
string sx1ICompl;		//мним. часть 1 корня
string sx2RCompl;		//действ. часть 2 корня
string sx2ICompl;		//мним. часть 2 корня
string discrim1;		//действ. часть дискр
string discrim2;		//мним. часть дискр

string deleteBracketsCompl(string s)	//удаление пробелов и скобок
{
	string temp = "";
	for (int i = 0; i < s.length(); i++)
		if (s[i] != ' ' && s[i] != '(' && s[i] != ')')
			temp += s[i];
	return temp;
}

bool checkCompl(System::String^ s)		//проверка на ошибки
{
	std::string equation = msclr::interop::marshal_as<std::string>(s);
	int iCounter = 0;
	int signCounter = 1;

	for (size_t i = 0; i < equation.length(); i++)
	{
		char a = equation[i];
		bool yes = false;
		for (size_t j = 0; j < checkEquationCompl.length(); j++)
			if (a == checkEquationCompl[j])
				yes = true;
		if (!yes)	//если нашелся запрещенный символ
		{
			ErrorCheckCompl = "Запрещенный символ";
			return false;
		}
		if (equation[i] == '.')		//если перед . нет числа
		{
			if (i == 0) 
			{
				ErrorCheckCompl = "Перед . нет числа";
				return false;
			}
			else if (!(equation[i - 1] >= '0' && equation[i - 1] <= '9'))
			{
				ErrorCheckCompl = "Перед . нет числа";
				return false;
			}
		}
		if (equation[i] == 'i')
			iCounter++;
		if (i != 0 && (equation[i] == '+' || equation[i] == '-'))
			signCounter++;
		if (i != equation.length() - 1)
		{
			if (equation[i] == 'i' && (equation[i + 1] != '+' && equation[i + 1] != '-'))	//если после i есть не знак
			{
				ErrorCheckCompl = "Число после i";
				return false;
			}
			if ((equation[i] == '-' || equation[i] == '+') && (equation[i + 1] == '-' || equation[i + 1] == '+'))	//++ -+ +- --
			{
				ErrorCheckCompl = "Проверьте знаки";
				return false;
			}
		}

	}
	if (iCounter > 1)
	{
		ErrorCheckCompl = "Проверьте кол-во мнимых чисел";
		return false;
	}
		
	if (signCounter > 2)
	{
		ErrorCheckCompl = "Может быть максимум 2 числа";
		return false;
	}
	if (signCounter == 2 && iCounter < 1)
	{
		ErrorCheckCompl = "Нет мнимой части";
		return false;
	}

	return true;
}

void TransformCompl(System::String^ s, char box)
{
	std::string eq = msclr::interop::marshal_as<std::string>(s);	//коэф
	int symb = 0;			//текущий символ в строке
	eq = deleteBracketsCompl(eq);	
	string imag = "";	//мнимая часть
	string real = "";	//действ часть

	string t1 = "";		//вспомогательная строка 1
	string t2 = "";		//вспомогательная строка 2
	int t1sign = 1;		//знак вспомогательной строки 1
	int t2sign = 1;		//знак вспомогательной строки 2
	int realsign = 1;	//знак действ части
	int imagsign = 1;	//знак мнимой части

	bool first = true;	//первая часть числа

	while (symb < eq.length())	//пока не дошла до конца строки
	{
		if (first)	//пока первая часть числа
		{
			if (symb == 0 && (eq[symb] == '+' || eq[symb] == '-'))	
			{
				if (eq[symb] == '-') //вычленяем знак первого числа 
					t1sign = -1;
				symb++;
			}
			else if (eq[symb] != '+' && eq[symb] != '-')
			{
				t1 += eq[symb];	//заполняем строку
				symb++;
			}
			else
				first = false;	//если первое число закончилось
		}
		else //если 2 часть числа
		{
			if (eq[symb] == '+' || eq[symb] == '-')
			{
				if (eq[symb] == '-')	//вычленяем знак 
					t2sign = -1;
				symb++;
			}
			else 
			{
				t2 += eq[symb];	//заполняем строку
				symb++;
			}
		}
	}

	if (t2 == "")		//если нет второй части числа
		if (t1[t1.size() - 1] == 'i')
			t2 = "0";
		else
			t2 = "0i";

	if (t1[t1.size() - 1] == 'i')	//заполнение real и imag частей
	{
		if (t1.size() == 1)
			imag = "1";
		else
		{
			t1.erase(t1.end()-1);
			imag = t1;
		}
		imagsign = t1sign;
	}
	else
	{
		real = t1;
		realsign = t1sign;
	}

	if (t2[t2.size() - 1] == 'i')	//заполнение real и imag частей
	{
		if (t2.size() == 1)
			imag = "1";
		else
		{
			t2.erase(t2.end()-1);
			imag = t2;
		}
		imagsign = t2sign;
	}
	else
	{
		real = t2;
		realsign = t2sign;
	}

	double realD;
	double imagD;
	realD = std::stod(real);	//полученные число приводим к double
	imagD = std::stod(imag);
	realD *= realsign;			//ставим знаки
	imagD *= imagsign;
	if (box == 'a')		//и записываем в переменные
	{
		complex<double> temp (realD, imagD);
		ACompl = temp;
	}
	else if (box == 'b')
	{
		complex<double> temp(realD, imagD);
		BCompl = temp;
	}
	else if (box == 'c')
	{
		complex<double> temp(realD, imagD);
		CCompl = temp;
	}
}

void eraserCompl(string& s)		//удаление ненужных частей числа
{
	bool imag = false;;
	if (s[s.size() - 1] == 'i')
	{
		imag = true;
		s.erase(s.size() - 1, 1);
	}
	if (s[s.size() - 1] == '0')
		for (size_t i = s.size() - 1; s[i] == '0'; i--)
			s.erase(i, 1);

	if (s[s.size() - 1] == '.')
		s.erase(s.size() - 1, 1);
	if (imag)
		s += 'i';

	if (s == "-0" || s == "-0i" || s == "0i" || s == "0" || s == "+0" || s == "+0i" || s == "+-0i" || s == "+0")
		s = "";
}

int solverCompl(complex<double> a, complex<double> b, complex<double> c)
{
	if (a.imag() == 0 && a.real() == 0)	//если не квадрат. ур.
	{
		return -1;
	}
	if (b.imag() == 0 && c.imag() == 0 && b.real() == 0 && c.real() == 0)	//если коэф B и C = 0
	{
		sx1RCompl = "0"; sx2RCompl = "0"; discrim1 = "0";
		sx1ICompl = ""; sx2ICompl = ""; discrim2 = "";
		return -2;
	}
	complex < double > four(4);	//число 4
	complex < double > two(2);	//число 2
	complex < double > D = (b * b) - (four * a * c);	//дискриминант
	Discr = D;
	complex < double > x1, x2;
	x1 = (-b + sqrt(D)) / (two * a);	//считаем корни
	x2 = (-b - sqrt(D)) / (two * a);

	//приводим в правильный вид и конвертируем в string
	sx1RCompl = to_string(x1.real());
	if (x1.imag() >= 0.0)
		sx1ICompl = "+" + to_string(x1.imag()) + "i";
	else
		sx1ICompl = to_string(x1.imag()) + "i";

	sx2RCompl = to_string(x2.real());
	if (x2.imag() >= 0.0)
		sx2ICompl = "+" + to_string(x2.imag()) + "i";
	else
		sx2ICompl = to_string(x2.imag()) + "i";
	discrim1 = to_string(Discr.real());
	if (Discr.imag() >= 0.0)
		discrim2 = "+" + to_string(Discr.imag()) + "i";
	else
		discrim2 = to_string(Discr.imag()) + "i";
	//удаляем лишнее
	eraserCompl(sx1RCompl);
	eraserCompl(sx1ICompl);
	eraserCompl(sx2RCompl);
	eraserCompl(sx2ICompl);
	eraserCompl(discrim1);
	eraserCompl(discrim2);

	return 0;
}

