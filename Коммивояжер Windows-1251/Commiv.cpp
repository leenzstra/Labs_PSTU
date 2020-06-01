#include "graph.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	glutInit(&argc, argv);

	setGraph(); //создание графа

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WinW, WinH);
	glutCreateWindow("window");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc(mouseMove);
	glutMainLoop();
}
