#pragma once
#include <vector>
#include <glut.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#define maxSize 20
using namespace std;

extern int WinW;		//ширина окна
extern int WinH;		//высота окна				

struct vertC			//структура координат вершин
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;		//вектор вершин
	int adjMatrix[maxSize][maxSize];//матрица смежности
	 
public:
	Graph();		//конструктор
	~Graph();		//деструктор

	bool IsEmpty();		//проверка на пустоту графа
	bool IsFull();		//проверка на полноту графа

	int GetAdjMatrixElem(int i, int j) { return adjMatrix[i][j]; }			//получение элемента матрицы смежности
	int GetVertListSize() { return vertList.size(); }				//получение кол-ва вершин графа
	int GetVertPos(const int& vertex);						//получить позицию вершины
	int GetAmountEdges();								//получить кол-во ребер

	void SetEdgeZero(int i, int j) { adjMatrix[i][j] = 0; adjMatrix[j][i] = 0; } //зануление элемента матрицы смежности
	void InsertVertex(const int& vertex);					//добавить вершину
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);	//добавить ребро

	void Print();								//печать матрицы смежности

	void eraseLastVert();							//удалить последнюю вершину
	void eraseEdge(const int& vertex1, const int& vertex2);			//удалить выбранное ребро
};

extern Graph graph;		//граф

//решение задачи коммивояжера
int** makeTSPMatrix();			//создаем матрицу и меняем 0 на -1
int* findMin(int* line, int n);		//поиск минимума в строке
void printMatrix(int** matrix);		//печать текущей матрицы
int** reductionLines(int** oldmatrix);	//редукция строк и столбцов
int** rebuildMatrix(int** oldmatrix);	//перестроение матрицы, нахождение отрезка пути
void printResult();			//печать найденного пути

//отрисовка
void drawBut1();			//отрисвка кнопок
void drawBut2();
void drawButSteps();
void drawBut3();
void drawButPath();
void drawBut4();
void drawBut5();
void drawBut6();
void drawSomeInfo();		//отрисовка информации о графе

void drawCircle(int x, int y, int R);				//нарисовать круг
void drawBorderedCircle(int x, int y, int R);			//нарисовать выделенный круг
void drawText(int nom, int x1, int y1);				//нарисовать текст
void drawLine(int text, int x0, int y0, int x1, int y1);	//нарисовать соединяющую линию
void drawVertex(int n);						//нарисовать вершину и текст (круг и текст)
void drawPathVertex(int n);					//визуализация пути коммивояжера
void drawGraph();						//нарисовать весь граф полностью
void setGraph();						//создание графа

void setCoords(int i, int n);					//установить координаты

bool checkSalesman(int** matrix);				//проверка на возможность задачи коммивояжера
int checkCircle(int x, int y);					//проверка на вхождение курсора в круг
void checkButton(int x, int y);					//проверка на вхождение курсора в кнопку

void drawLineCut(int x, int y);								//отрисовка отрезающей линии
bool cross(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22);	//нахождение точки пересечения отрез. линии и ребра (ребер)
void deleteEdgeByCut();									//удаление выбранного (или выбранных) ребра (ребер)

void mouseMove(int x, int y);					//отслеживание движения мыши
void mouseClick(int button, int state, int x, int y);		//отслеживание нажатий мыши
void reshape(int w, int h);					//решейп
void display();							//отрисовка содержимого окна


