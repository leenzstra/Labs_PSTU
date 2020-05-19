#include <string>
#include <msclr/marshal_cppstd.h>
#include <complex>
using namespace std;

complex<double> ACompl;		//���� �
complex<double> BCompl;		//���� �
complex<double> CCompl;		//���� �
complex<double> Discr;		//������������

string checkEquationCompl = "1234567890-+.i()";	//�������� �� ������
string ErrorCheckCompl;		//������

string sx1RCompl;		//������. ����� 1 �����
string sx1ICompl;		//����. ����� 1 �����
string sx2RCompl;		//������. ����� 2 �����
string sx2ICompl;		//����. ����� 2 �����
string discrim1;		//������. ����� �����
string discrim2;		//����. ����� �����

string deleteBracketsCompl(string s)	//�������� �������� � ������
{
	string temp = "";
	for (int i = 0; i < s.length(); i++)
		if (s[i] != ' ' && s[i] != '(' && s[i] != ')')
			temp += s[i];
	return temp;
}

bool checkCompl(System::String^ s)		//�������� �� ������
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
		if (!yes)	//���� ������� ����������� ������
		{
			ErrorCheckCompl = "����������� ������";
			return false;
		}
		if (equation[i] == '.')		//���� ����� . ��� �����
		{
			if (i == 0) 
			{
				ErrorCheckCompl = "����� . ��� �����";
				return false;
			}
			else if (!(equation[i - 1] >= '0' && equation[i - 1] <= '9'))
			{
				ErrorCheckCompl = "����� . ��� �����";
				return false;
			}
		}
		if (equation[i] == 'i')
			iCounter++;
		if (i != 0 && (equation[i] == '+' || equation[i] == '-'))
			signCounter++;
		if (i != equation.length() - 1)
		{
			if (equation[i] == 'i' && (equation[i + 1] != '+' && equation[i + 1] != '-'))	//���� ����� i ���� �� ����
			{
				ErrorCheckCompl = "����� ����� i";
				return false;
			}
			if ((equation[i] == '-' || equation[i] == '+') && (equation[i + 1] == '-' || equation[i + 1] == '+'))	//++ -+ +- --
			{
				ErrorCheckCompl = "��������� �����";
				return false;
			}
		}

	}
	if (iCounter > 1)
	{
		ErrorCheckCompl = "��������� ���-�� ������ �����";
		return false;
	}
		
	if (signCounter > 2)
	{
		ErrorCheckCompl = "����� ���� �������� 2 �����";
		return false;
	}
	if (signCounter == 2 && iCounter < 1)
	{
		ErrorCheckCompl = "��� ������ �����";
		return false;
	}

	return true;
}

void TransformCompl(System::String^ s, char box)
{
	std::string eq = msclr::interop::marshal_as<std::string>(s);	//����
	int symb = 0;			//������� ������ � ������
	eq = deleteBracketsCompl(eq);	
	string imag = "";	//������ �����
	string real = "";	//������ �����

	string t1 = "";		//��������������� ������ 1
	string t2 = "";		//��������������� ������ 2
	int t1sign = 1;		//���� ��������������� ������ 1
	int t2sign = 1;		//���� ��������������� ������ 2
	int realsign = 1;	//���� ������ �����
	int imagsign = 1;	//���� ������ �����

	bool first = true;	//������ ����� �����

	while (symb < eq.length())	//���� �� ����� �� ����� ������
	{
		if (first)	//���� ������ ����� �����
		{
			if (symb == 0 && (eq[symb] == '+' || eq[symb] == '-'))	
			{
				if (eq[symb] == '-') //��������� ���� ������� ����� 
					t1sign = -1;
				symb++;
			}
			else if (eq[symb] != '+' && eq[symb] != '-')
			{
				t1 += eq[symb];	//��������� ������
				symb++;
			}
			else
				first = false;	//���� ������ ����� �����������
		}
		else //���� 2 ����� �����
		{
			if (eq[symb] == '+' || eq[symb] == '-')
			{
				if (eq[symb] == '-')	//��������� ���� 
					t2sign = -1;
				symb++;
			}
			else 
			{
				t2 += eq[symb];	//��������� ������
				symb++;
			}
		}
	}

	if (t2 == "")		//���� ��� ������ ����� �����
		if (t1[t1.size() - 1] == 'i')
			t2 = "0";
		else
			t2 = "0i";

	if (t1[t1.size() - 1] == 'i')	//���������� real � imag ������
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

	if (t2[t2.size() - 1] == 'i')	//���������� real � imag ������
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
	realD = std::stod(real);	//���������� ����� �������� � double
	imagD = std::stod(imag);
	realD *= realsign;			//������ �����
	imagD *= imagsign;
	if (box == 'a')		//� ���������� � ����������
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

void eraserCompl(string& s)		//�������� �������� ������ �����
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
	if (a.imag() == 0 && a.real() == 0)	//���� �� �������. ��.
	{
		return -1;
	}
	if (b.imag() == 0 && c.imag() == 0 && b.real() == 0 && c.real() == 0)	//���� ���� B � C = 0
	{
		sx1RCompl = "0"; sx2RCompl = "0"; discrim1 = "0";
		sx1ICompl = ""; sx2ICompl = ""; discrim2 = "";
		return -2;
	}
	complex < double > four(4);	//����� 4
	complex < double > two(2);	//����� 2
	complex < double > D = (b * b) - (four * a * c);	//������������
	Discr = D;
	complex < double > x1, x2;
	x1 = (-b + sqrt(D)) / (two * a);	//������� �����
	x2 = (-b - sqrt(D)) / (two * a);

	//�������� � ���������� ��� � ������������ � string
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
	//������� ������
	eraserCompl(sx1RCompl);
	eraserCompl(sx1ICompl);
	eraserCompl(sx2RCompl);
	eraserCompl(sx2ICompl);
	eraserCompl(discrim1);
	eraserCompl(discrim2);

	return 0;
}

