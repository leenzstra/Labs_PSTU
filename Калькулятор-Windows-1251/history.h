#pragma once
#include <vector>
#include <string>
using namespace std;

struct historyNote	//��������� ���������
{
	string eq;		//���������
	string x1;		//�����
	string x2;
	string type;	//���
};

vector<historyNote> historyNotes;	//������ ����. 6 ��.

string tip1 = "��������� ������ ��� ���������!!! >:(";
string tip2 = "�������� ������� ��������� ���, � ���� ����������� ������ ������������ :P";
string tip3 = "���� ���� ������, ����� ������ :)";
string tip4 = "������� ������ �������� 6 �������! :B";
string tip5 = "���� ����������� � = 0, �� ��� ��� �� ���������� ���������! :<";
string tip6 = "����� ������ �����, ����� �� ����� <:(";
string tip7 = "�������� ���� �� ������� ��� :�";
string tip8 = "��������� ���� ����������� ����� ������ :>";
string tip9 = "����� settings.txt ����� �������� ���� ^v^";

vector<string> tips = { tip1, tip2, tip3, tip4, tip5, tip6, tip7, tip8,tip9 };	//������

string randomTip()	//����� ���������� ������
{
	int num = rand() % tips.size();
	return tips[num];
}

string solvedNum;	//���-�� �������� ���������
long solvedNumber;	//�� ��� �����