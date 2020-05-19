#pragma once
#include <vector>
#include <string>
using namespace std;

struct historyNote	//структура уравнения
{
	string eq;		//уравнение
	string x1;		//корни
	string x2;
	string type;	//тип
};

vector<historyNote> historyNotes;	//вектор макс. 6 эл.

string tip1 = "Используй скобки для выражений!!! >:(";
string tip2 = "Старайся считать выражения сам, а сюда подставлять только коэффициенты :P";
string tip3 = "Если меню мешает, можно убрать :)";
string tip4 = "История хранит максимум 6 записей! :B";
string tip5 = "Если коэффициент А = 0, то это уже не квадратное уравнение! :<";
string tip6 = "Чтобы убрать совет, намжи на текст <:(";
string tip7 = "Переноси окно за верхний бар :Б";
string tip8 = "Настройки темы сохраняются после выхода :>";
string tip9 = "Удали settings.txt чтобы сбросить тему ^v^";

vector<string> tips = { tip1, tip2, tip3, tip4, tip5, tip6, tip7, tip8,tip9 };	//советы

string randomTip()	//выбор случайного совета
{
	int num = rand() % tips.size();
	return tips[num];
}

string solvedNum;	//кол-во решенный уравнений
long solvedNumber;	//за все время
