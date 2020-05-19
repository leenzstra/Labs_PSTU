#include "graph.h"
using namespace std;

int WinW = 1280;					//������ ����
int WinH = 720;						//������ ����
				
bool printSteps = false;			//�������� ���� ��� ���
bool drawing = true;				//�������� �� ��������� ����� ����			
bool* onMouse = new bool[maxSize];	//���� ���� �� ������� - true
bool movable = false;				//����� ������������, ��� ���������������
bool moving = false;				//������� ������� - true

bool cutting = false;				//����� - true

vector<pair<int, int>> path;		//������ �������� ���� ������������
vector<int> newpath;				//������ ������� ���� ������������
int R;								//������ ������

int curNode;						//������� ��������� �������
int curPosX;						//������� ������� �
int curPosY;						//������� ������� Y

vertC vC[maxSize + 2];				//������ ���������

pair<int, int> lineFirst;			//���������� ������� ����� X
pair<int, int> lineSecond;			//���������� ������� ����� Y

Graph graph;						//����

int buttonsState;					//�������� �� ��������� ������� �� ������

int maxRad; int minRad = 10;		//����. � ���. �������





Graph::Graph()		//���������� ������� ��������� ������ � ������� ��������� ������� � �������
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
			adjMatrix[i][j] = 0;
		onMouse[i] = false;			
	}
}

Graph::~Graph()		//����������
{}

int Graph::GetVertPos(const int& vertex)	//�������� ������� �������
{
	for (size_t i = 0; i < vertList.size(); i++)
		if (vertList[i] == vertex)
			return i;
	return -1;
}

bool Graph::IsEmpty()
{
	if (vertList.size() != 0)
		return false;
	else
		return true;		//���� ���� ���������� true
}

bool Graph::IsFull()
{
	return (vertList.size() == maxSize);	//���� ����� ���������� true
}

void Graph::InsertVertex(const int& vertex)
{
	if (!IsFull())		//���� ���� �� ����� �� ��������� �������
		vertList.push_back(vertex);
	else
	{
		cout << "���� ��������!" << endl;
		return;
	}
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (weight < 1)	//���� ��� ����� �������������, �� ��������� �������
	{
		cout << "\n����� ��� �� ����� ����.\n";
		return;
	}
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))						//���� ������� ���� � �����
	{
		int vertPos1 = GetVertPos(vertex1);												//������� ������� ������
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] != 0 && adjMatrix[vertPos2][vertPos1] != 0)	//���� ����� ���� ��� ���� �����
		{
			cout << "����� ����� ��������� ��� ����" << endl;							//�� ������������
			return;
		}
		else																			//����� ��������� �����
		{
			adjMatrix[vertPos1][vertPos2] = weight;
			adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "����� ������ (��� ����� �� ���) ��� � ����� " << endl;
		return;
	}
}

void Graph::Print()
{
	if (!IsEmpty())											//���� ���� �� ����
	{
		cout << "������� ��������� �����: " << endl;		//�� �������� �������� ������� ���������
		for (size_t i = 0; i < vertList.size(); i++)
		{
			cout << vertList[i] << " ";
			for (size_t j = 0; j < vertList.size(); j++)
				cout << setw(4) << adjMatrix[i][j];
			cout << endl;
		}
	}
	else
		cout << "���� ����!" << endl;
}

void Graph::eraseLastVert()
{
	if (IsEmpty())					//���� ���� ����� - ������������
	{
		cout << "\n���� ����\n";
		return;
	}

	int n = vertList.size();		
	for (int j = 0; j < n; j++)		//����� �������� ����� ��������� �������
		SetEdgeZero(n - 1, j);

	vertList.pop_back();			//� ������� �� �� ������� ������
}

void Graph::eraseEdge(const int& vertex1, const int& vertex2)
{
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))						//���� ������� ���� � �����
	{
		int vertPos1 = GetVertPos(vertex1);												//������� ������� ������
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] == 0 && adjMatrix[vertPos2][vertPos1] == 0)	//���� ����� ���� ��� ��� �����
		{
			cout << "����� ����� ���!" << endl;											//�� ������������
			return;
		}
		else																			//����� �������� ������ �����
			SetEdgeZero(vertPos1, vertPos2);
	}
	else
	{
		cout << "����� ������ (��� ����� �� ���) ��� � �����!" << endl;
		return;
	}
}

int Graph::GetAmountEdges()
{
	int edges = 0;
	for (int i = 0; i < vertList.size(); i++)				//���������� �� 2 ������������ ����� �������, �� ������� ���������
		for (int j = i + 1; j < vertList.size(); j++)
			if (adjMatrix[i][j] > 0)						//���� ������� ������ ����
				edges++;									//�� ���-�� ����� +1
	return edges;
}

int** makeTSPMatrix()	//������� ������� � ������ 0 �� -1
{
	int n = graph.GetVertListSize();
	int** matrix = new int* [n];		//������� ������� �������� ��� ������� ���������
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int elem = graph.GetAdjMatrixElem(i, j);	//�������� ��� �������� �� ������� ���������
			if (elem == 0 or i == j)					//���� ��� �����, �� ������ �� -1 �� 0 ����� �������������
				matrix[i][j] = -1;
			else
				matrix[i][j] = elem;
		}

	if (printSteps)								//���� �������� ������ �����
	{
		cout << "�������������� �������: \n";	//�� �������� �������
		printMatrix(matrix);
	}
	return matrix;
}

int* findMin(int* line, int n)	
{
	int min = 1000000;
	for (int j = 0; j < n; j++)					//����� �������� � ������
		if (line[j] >= 0 && line[j] < min)
			min = line[j];

	for (int j = 0; j < n; j++)					//� ��������� ��� �� ������� �������� ������
		if (line[j] >= 0)
			line[j] -= min;
	return line;
}

void printMatrix(int** matrix)		//������ ������� �������
{
	int n = graph.GetVertListSize();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
}

int** reductionLines(int** oldmatrix)		//�������� ����� � ��������
{
	int** matrix = oldmatrix;				//�������� ������ �������
	int n = graph.GetVertListSize();
	for (int i = 0; i < n; i++)				//���������� ������� ������
		matrix[i] = findMin(matrix[i], n);

	for (int i = 0; i < n; i++)				//����� ������
	{
		int min = 1000000;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0 && matrix[j][i] < min)
				min = matrix[j][i];
		}
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0)
				matrix[j][i] -= min;
		}
	}
	if (printSteps)							//���� �������� ������ �����
	{
		cout << "\n�������������� �������: \n";
		printMatrix(matrix);				//�� �������� �������
	}
	return matrix;
}

int** rebuildMatrix(int** oldmatrix)
{
	int n = graph.GetVertListSize();
	int** matrix = reductionLines(oldmatrix);	//��������� �������������� �������

	int max = -1;
	int line, column;

	for (int i = 0; i < n; i++)					//����� 0 � ���������� �������
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)				//���� ����� 0 � �������
			{
				int minLine = 1000000;
				int minColumn = 1000000;
				for (int k = 0; k < n; k++)
				{
					if (matrix[i][k] != -1 && k != j && matrix[i][k] < minLine)			//����� �������� � ������
						minLine = matrix[i][k];
				}
				for (int k = 0; k < n; k++)
				{
					if (matrix[k][j] != -1 && k != i && matrix[k][j] < minColumn)		//����� �������� � �������
						minColumn = matrix[k][j];
				}
				if (max < minColumn + minLine)		//���� ����� ��������� ������ �������� ���������
				{
					max = minColumn + minLine;		//�� ������������ ��������
					line = i;						//� ���������� ��������� �������� 0 � �������
					column = j;
				}									//��� � ���� ������� ����
			}
		}
	}

	pair<int, int> p;		//���������� ������� � pair
	p.first = line + 1;		//������ (+1 �.�. ������ � 0)
	p.second = column + 1;	//����
	path.push_back(p);		//� ������ � ������ �������� ����

	matrix[line][column] = -1;		//�������� ���� � ����. ������� c ����� �����
	matrix[column][line] = -1;		//�������� ���� � ����. ������� � ������ �����

	for (int i = 0; i < n; i++)		//�������� ������ ������� ������� ���� �� ������
	{
		matrix[line][i] = -1;
		matrix[i][column] = -1;
	}
	if (printSteps)		//���� �������� ������ �����
	{
		cout << endl;
		cout << "������� ����� �������� ����������� 0: \n";
		printMatrix(matrix);				//����� ������� ������� ����� ��������
		cout << "\n����� ����: ";
		for (int i = 0; i < path.size(); i++)	//� ������ ����
			cout << path[i].first << " -> " << path[i].second << "   ";
		cout << endl;
	}
	return matrix;
}

void printResult()
{
	//newpath - ������ ������� ���� ������������
	int second = path[0].second;		//2 ����� ����� ����						
	newpath.push_back(path[0].first);	//��������� 1 �����
	newpath.push_back(path[0].second);	//2 �����
	int i = 2;							//���-�� ����������� �������

	while (i != graph.GetVertListSize() + 1)			//���� �� �������� ��� ������
		for (int j = 1; j < graph.GetVertListSize(); j++)
			if (path[j].first == second)				//���� ������ ������� �������� ������� ���� (������) ����� ����� ����������� ������� ����
			{
				second = path[j].second;				//�� ����� ����� - ����� �������� ������� ����
				newpath.push_back(second);				//� ���������� ��� ��� ����. ����� ����
				i++;
			}											//����� ������� ������������ ������ ���� � ��������� ����� - � ��������� �����

	cout << "����: ";
	for (int i = 0; i < newpath.size(); i++)			//������ ������� ����
	{
		cout << newpath[i];
		if (i != newpath.size() - 1)
			cout << " -> ";
	}

	int sum = 0;
	for (int i = 0; i < path.size(); i++)				//���������� ����� ����
	{
		int line = path[i].first - 1;
		int column = path[i].second - 1;
		sum += graph.GetAdjMatrixElem(line, column);
	}
	cout << "\n���������� ����� ����: " << sum << endl;;
}

void drawBut1()
{
	if (buttonsState == 1)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(0, WinH);
	glVertex2i(0, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH);
	glVertex2i(0, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH);
	glEnd();

	string but1 = "Print";
	string but2 = "matrix";
	glRasterPos2i(4, WinH - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, WinH - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawBut2()
{
	if (buttonsState == 2)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(0, WinH - (WinH / 6));
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - (WinH / 6));
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - (WinH / 6));
	glEnd();

	string but1 = "Salesman";
	string but2 = "problem";
	glRasterPos2i(4, WinH - (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, WinH - (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawButSteps()
{
	if (printSteps)
		glColor3f(0.0f, 0.5f, 0.0f);
	else
		glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(0, WinH / 6);
	glVertex2i(WinW / 6, WinH / 6);
	glVertex2i(WinW / 6, 0);
	glEnd();
}

void drawBut3()
{
	if (buttonsState == 3)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(0, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(0, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glEnd();

	string but1 = "New";
	string but2 = "graph";
	glRasterPos2i(4, WinH - 2 * (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, WinH - 2 * (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);
}

void drawButPath()
{
	if (drawing)
		glColor3f(0.0f, 0.0f, 1.0f);
	else
		glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2i(WinW, 0);
	glVertex2i(WinW, WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH / 6);
	glVertex2i(5 * (WinW / 6), 0);
	glEnd();
}

void drawBut4()
{
	if (buttonsState == 4)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(WinW, WinH);
	glVertex2i(WinW, WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(WinW, WinH);
	glVertex2i(WinW, WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH);
	glEnd();

	string but1 = "Rescale";
	string but2 = "Rebuild";
	glRasterPos2i(5 * (WinW / 6) + 4, WinH - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(5 * (WinW / 6) + 4, WinH - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawBut5()
{
	if (buttonsState == 5)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(WinW, WinH - (WinH / 6));
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(WinW, WinH - (WinH / 6));
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - (WinH / 6));
	glEnd();

	string but1 = "Add / delete";
	string but2 = "LAST vert";
	glRasterPos2i(5 * (WinW / 6) + 4, 5 * (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(5 * (WinW / 6) + 4, 5 * (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawBut6()
{
	if (buttonsState == 6)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(WinW, WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(WinW, WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glEnd();

	string but1 = "Add / delete";
	string but2 = "edges";
	glRasterPos2i(5 * (WinW / 6) + 4, 4 * (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(5 * (WinW / 6) + 4, 4 * (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawCircle(int x, int y, int R) //���� � �������� �����������
{
	glColor3f(0.9f, 0.9f, 0.9f);
	float x1, y1;
	glBegin(GL_POLYGON);			//����
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);			//����������
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawBorderedCircle(int x, int y, int R) //���� � �������� �����������
{
	glColor3f(0.686, 0.933, 0.933);
	float x1, y1;
	glBegin(GL_POLYGON);		//����
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.000, 0.000, 0.502);
	float x2, y2;
	glBegin(GL_LINE_LOOP);		//����������
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1)		//������ ��� ����� ����� 2 ���������
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;	//�����
	string s = to_string(nom);					//�����
	glRasterPos2i(x1 - 5, y1 - 5);				//��������� �������
	for (size_t j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);		//��������� �����������
}

void drawLine(int text, int x0, int y0, int x1, int y1) 
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);		//����� ������������������ ����������� ����� 
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);  
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}

void drawVertex(int n)		//��������� �������
{
	for (int i = 0; i < n; i++)
	{
		if (onMouse[i])		//���� ������ � ���� �����
			drawBorderedCircle(vC[i].x, vC[i].y, R);
		else
			drawCircle(vC[i].x, vC[i].y, R);
		drawText(i + 1, vC[i].x, vC[i].y);
	}

}

void drawPathVertex(int n)		//��������� ����
{
	if (newpath.empty())	//���� ������ ������������ �� ���� ������
	{
		drawGraph();
		cout << "\n������� ������ ������ ������������!!!\n";
		drawing = true;
		return;
	}

	glutSwapBuffers();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int k = 0; k < graph.GetVertListSize(); k++)	//������ ��� ������� �����
	{
		int n1 = newpath[k]; n1--;
		drawBorderedCircle(vC[n1].x, vC[n1].y, R);
		drawText(newpath[k], vC[n1].x, vC[n1].y);
	}
	Sleep(1000);		//�������� ����� �������� ���������������
	glutSwapBuffers();

	for (int i = 0; i < graph.GetVertListSize(); i++)
	{
		for (int j = 0; j <= i; j++)		//�� ������� ���� ��������������� ����� �������
		{
			int n1 = newpath[j]; n1--;
			int n2 = newpath[j + 1]; n2--;
			drawLine(graph.GetAdjMatrixElem(n1, n2), vC[n1].x, vC[n1].y, vC[n2].x, vC[n2].y);		//� ������ ����� ����� ����
		}
		for (int k = 0; k < graph.GetVertListSize(); k++)		//� ����� ������ ��� �������
		{
			int n1 = newpath[k]; n1--;
			drawBorderedCircle(vC[n1].x, vC[n1].y, R);
			drawText(newpath[k], vC[n1].x, vC[n1].y);
		}
		Sleep(1000);			//�������� ����� �������� ���������������
		glutSwapBuffers();
	}

	//��������� ��������� 2 ������ (����� � ������) � ����� ����� ����
	drawLine(graph.GetAdjMatrixElem(newpath[0] - 1, newpath[newpath.size() - 2] - 1), vC[newpath[0] - 1].x, vC[newpath[0] - 1].y, vC[newpath[newpath.size() - 2] - 1].x, vC[newpath[newpath.size() - 2] - 1].y);
	drawBorderedCircle(vC[newpath[0] - 1].x, vC[newpath[0] - 1].y, R);
	drawText(newpath[0], vC[newpath[0] - 1].x, vC[newpath[0] - 1].y);
	drawBorderedCircle(vC[newpath[newpath.size() - 2] - 1].x, vC[newpath[newpath.size() - 2] - 1].y, R);
	drawText(newpath[newpath.size() - 2], vC[newpath[newpath.size() - 2] - 1].x, vC[newpath[newpath.size() - 2] - 1].y);
	glutSwapBuffers();
	Sleep(2000);
	drawing = true;

}

void setCoords(int i, int n)	//��������� ��������� ������� � �����. �� �������� ����
{
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else
	{
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * i / n;
	int y1 = R_ * cos(theta) + y0;
	int x1 = R_ * sin(theta) + x0;
	vC[i].x = x1;
	vC[i].y = y1;
}

void drawGraph()		//��������� ���������� �����
{
	int n = graph.GetVertListSize();
	for (int i = 0; i < n; i++)
	{
		if (!movable)			//���� �� ������� �������, �� ���������� �� ���������������, �.�. �� ���� �� �������������
			setCoords(i, n);	//��������� ���������
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = graph.GetAdjMatrixElem(i, j);
			if (a != 0)												//���� ���� ����
				drawLine(a, vC[i].x, vC[i].y, vC[j].x, vC[j].y);	//�� ������� �����
		}
	}
	drawVertex(n);		//������ �������
	glutPostRedisplay();
}

void setGraph()	//�������� �����
{
	movable = false;			//�������� ����� � ����

	int amountVerts, amountEdges, sourceVertex, targetVertex, edgeWeight;
	cout << "������� ���������� ������ �����: "; cin >> amountVerts;
	cout << "������� ���������� ����� �����: "; cin >> amountEdges;
	for (int i = 1; i <= amountVerts; i++) {

		graph.InsertVertex(i);
	}
	for (int i = 0; i < amountEdges; i++)
	{
		cout << "�������� �������: "; cin >> sourceVertex;
		cout << "�������� �������: "; cin >> targetVertex;
		cout << "��� �����: "; cin >> edgeWeight;
		graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
	}
	cout << endl;
	graph.Print();
}

bool checkSalesman(int** matrix)
{
	if (graph.IsEmpty())
		return false;
	for (int i = 0; i < graph.GetVertListSize(); i++)
	{
		int counter = 0;
		for (int j = 0; j < graph.GetVertListSize(); j++)		//���� ���� �������, � ������� ������ 1 ����
		{
			if (matrix[i][j] > 0)								//�� ����� ������ �� ������
				counter++;
		}
		if (counter <= 1)
			return false;
	}
	return true;
}

int checkCircle(int x, int y) //��������� ������ �� ���� � ���� �����
{
	for (int i = 0; i < graph.GetVertListSize(); i++)
		if (pow(x - vC[i].x, 2) + pow(y - vC[i].y, 2) <= pow(R, 2))
			return i;	//���������� ������ ������� � �������
	return -1;
}

void drawLineCut(int x, int y)	//��������� ������� �����
{
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2i(lineFirst.first, lineFirst.second);		//���������� ������
	glVertex2i(x, y);									//���������� �����
	glEnd();
}

void checkButton(int x, int y)		//�������� �� ��������� ������� � ������� ������ � ����������� ������ ������
{
	if (x < (WinW / 6) && y > 5 * (WinH / 6))
		buttonsState = 1;
	else if (x < (WinW / 6) && y < 5 * (WinH / 6) && y > 4 * (WinH / 6))
		buttonsState = 2;
	else if (x < (WinW / 6) && y < 4 * (WinH / 6) && y > 3 * (WinH / 6))
		buttonsState = 3;
	else if (x > 5 * (WinW / 6) && y > 5 * (WinH / 6))
		buttonsState = 4;
	else if (x > 5 * (WinW / 6) && y < 5 * (WinH / 6) && y > 4 * (WinH / 6))
		buttonsState = 5;
	else if (x > 5 * (WinW / 6) && y < 4 * (WinH / 6) && y > 3 * (WinH / 6))
		buttonsState = 6;
	else
		buttonsState = 0;
}

void mouseMove(int x, int y) //������� ������������ �������� ����
{
	y = WinH - y;
	curPosX = x;	//������� ������� �������
	curPosY = y;

	int i = checkCircle(x, y);	//�������� �� ��������� ������� � �������
	if (i != -1)
		onMouse[i] = true;	//���� ���� ����� �������, �� ������� ������� � �������� ������� - true
	else
		for (int j = 0; j < graph.GetVertListSize(); j++)
			onMouse[j] = false;
	if (moving)		//����� ������� �������, �� �� ��������� = ���������� �������
	{
		vC[curNode].x = curPosX;
		vC[curNode].y = curPosY;
	}
	checkButton(x, y);	//�������� �� ��������� � ���� ������
	glutPostRedisplay();
}

bool cross(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22)
{
	//�������� �� ��������� 2 ����� 2 ���������
	double a1 = y12 - y11;
	double b1 = x11 - x12;
	double c1 = a1 * (x11)+b1 * (y11);

	double a2 = y22 - y21;
	double b2 = x21 - x22;
	double c2 = a2 * (x21)+b2 * (y21);

	double determinant = a1 * b2 - a2 * b1;

	//����� ����� �����������
	double x;
	double y;
	if (determinant == 0)
		return false;
	else
	{
		x = (b2 * c1 - b1 * c2) / determinant;
		y = (a1 * c2 - a2 * c1) / determinant;
	}
	cout << x << ' ' << y << endl;
	
	//���� ����� ����������� ������ � ���� ����������� ���� ������, ���������� true
	if ((x11 <= x && x12 >= x) or (x11 >= x && x12 <= x))
	{
		if (x21 >= x && x22 <= x)
		{
			if (y21 >= y && y22 <= y)
			{
				return true;
			}
			else if (y21 <= y && y22 >= y)
			{
				return true;
			}
		}
		else if (x21 <= x && x22 >= x)
		{
			if (y21 >= y && y22 <= y)
			{
				return true;
			}
			else if (y21 <= y && y22 >= y)
			{
				return true;
			}
		}
	}
	//����� false
	return false;

}

void deleteEdgeByCut()
{
	int n = graph.GetVertListSize();

	for (int i = 0; i < n; i++)			//������ �� 2 ������������ ����� �������
	{
		for (int j = i + 1; j < n; j++)
		{
			bool cut = false;;
			int elem = graph.GetAdjMatrixElem(i, j);
			if (elem != 0)	//���� ���� �����, �� ��������� ��� �� ����������� � ���������� ������
				cut = cross(lineFirst.first, lineSecond.first, lineFirst.second, lineSecond.second, vC[i].x, vC[j].x, vC[i].y, vC[j].y);
			if (cut)	//���� ����������� ����, �� �������� ����� (�������)
			{
				graph.SetEdgeZero(i, j);
				/*return;*/   //return - ���� ����� ������� ������ 1 �����, ���� ������ - ��� ������������ ������� ������ 
			}
		}
	}
}

void drawSomeInfo()
{
	int radius = 0;
	if (graph.GetVertListSize() != 0)	//���� ���� ���� - �� ����� ��� ������
		radius = R;
	int space = 24;						//������ ����� ��������
	string rad = "Radius: " + to_string(radius);	//������
	string verts = "Verts: " + to_string(graph.GetVertListSize());	//�������
	string edges = "Edges: " + to_string(graph.GetAmountEdges());	//�����

	if (R == maxRad || R == minRad)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);

	glRasterPos2i(5 * (WinW / 6), WinH - 3 * (WinH / 6) - space);
	for (int i = 0; i < rad.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, rad[i]);

	if (graph.GetVertListSize() == 20)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2i(5 * (WinW / 6), WinH - 3 * (WinH / 6) - space*2);
	for (int i = 0; i < verts.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, verts[i]);

	glRasterPos2i(5 * (WinW / 6), WinH - 3 * (WinH / 6) - space * 3);
	for (int i = 0; i < edges.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, edges[i]);
}

void mouseClick(int button, int state, int x, int y) //������������ �������
{
	int i = checkCircle(x, WinH - y);	//��������� ��������� ������� � ������� �������

	if (moving)		//���� ������� � ������ �����������, �� ��� ������� ����� ����
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			cout << "no moving" << endl;
			moving = false;
			return;
		}
	}

	if (i != -1)		//���� ������ � ���� �����
	{
		movable = true;		//�� ���� �� ����������������
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			//� ��� ������� ��� ����� ����������� ��� ������ �������
			cout << "moving" << endl;
			moving = true;
			curNode = i;		//������ ������ �������
			return;
		}
	}

	if (button == 3 || button == 4)		//��������� ������� ������� ��������� ����
	{
		movable = true;		//���� �� ����������������
		if (button == 3 && R < maxRad)	//���� ������ ����� - ������ �������������
			R++;
		else if (button == 4 && R > minRad)	//���� ���� - �����������
			R--;							//���� ����������� �� ������ �������
	}

	if (x <= (WinW / 6) and y <= (WinH / 6)) //1 ������ - ������ �����
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			graph.Print();
			return;
		}

	if (x <= (WinW / 6) and y <= 2 * (WinH / 6) and y > (WinH / 6)) //2 ������ - ������� ������ ������������
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			newpath.clear();
			path.clear();
			cout << "\n\n\n������� ������ ������������: \n\n\n";
			int** matrix = makeTSPMatrix();		//�������� ����� �������
			bool checker = checkSalesman(matrix);	//�������� �� ����������� �������
			if (!checker)
			{
				cout << "������ ���� �� ������������ ������ �����������";
				return;
			}

			int n = graph.GetVertListSize();
			while (path.size() < n)				//���� �� ������ ��� ������� ����
				matrix = rebuildMatrix(matrix);	//����������� �������
			cout << endl;						//� ����� ��������� �������, ����������� -1
			printResult();
			return;
		}
	}
	if (x <= (WinW / 6) and y > 5 * (WinH / 6))			//������ ������ �����
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (printSteps)
			{
				printSteps = false;
				cout << "\n����� ����� ����\n";
			}

			else
			{
				printSteps = true;
				cout << "\n����� ����� ���\n";
			}
			return;
		}
	}
	if (x <= (WinW / 6) and y <= 3 * (WinH / 6) and y > 2 * (WinH / 6))		//3 ������ - �������� �����
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			newpath.clear();
			path.clear();
			Graph newgraph;
			graph = newgraph;
			setGraph();
			return;
		}
	}
	if (x >= (5 * (WinW / 6)) and y >= 5 * (WinH / 6))	//������ ��������� ����
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (drawing)
				drawing = false;
			else
				drawing = true;
			return;
		}
	}
	if (x >= 5 * (WinW / 6) and y <= (WinH / 6))		//4 ������ - ����������� ���� ������
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			movable = false;
			return;
		}
	}

	if (x >= 5 * (WinW / 6) and y <= 2 * (WinH / 6) and y > (WinH / 6))	//5 ������ - ���������� � �������� �������
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int cur = graph.GetVertListSize();
			graph.InsertVertex(cur + 1);
			vC[cur].x = WinW / 2;
			vC[cur].y = WinH / 2;
			cout << "\n��������� ������� " << cur + 1 << endl;
			return;
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			graph.eraseLastVert();
			int cur = graph.GetVertListSize();
			cout << "\n������� ������� " << cur+1 << endl;
			return;
		}
	}
	if (x >= 5 * (WinW / 6) and y <= 3 * (WinH / 6) and y > 2 * (WinH / 6))	//6 ������ - ���������� � �������� �������
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex, edgeWeight, vertNum;
			cout << "���-�� ����� �����: "; cin >> vertNum;
			for (int i = 0; i < vertNum; i++)
			{
				cout << "�������� �������: "; cin >> sourceVertex; 
				cout << "�������� �������: "; cin >> targetVertex; 
				cout << "��� �����: "; cin >> edgeWeight; 
				graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
			}
			return;
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex;
			cout << "�������� �������: "; cin >> sourceVertex; 
			cout << "�������� �������: "; cin >> targetVertex; 
			graph.eraseEdge(sourceVertex, targetVertex);
			return;
		}
	}
	if (cutting)		//���� ��� ����� ����� �����
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			cutting = false;				//�� ��� ������� �� ����
			lineSecond.first = curPosX;		//�������� ������ �����
			lineSecond.second = curPosY;
			cout << "nocutting\n";
			deleteEdgeByCut();				//� ��������� ��� (��� 1
		}
	}
	else			//���� ����� ����, �� �������� �������� �����
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			cutting = true;
			lineFirst.first = curPosX;
			lineFirst.second = curPosY;
			cout << "cutting\n";
		}
	}

}

void reshape(int w, int h)	//������ � ��������� ����� �������� ����
{
	WinW = w;
	WinH = h;

	if (WinW >= WinH)		//������� ����. �������
		maxRad = WinH / 2;
	else
		maxRad = WinW / 2;

	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void display()
{
	glMatrixMode(GL_PROJECTION);	//��������� ����� ���. ���������
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (drawing)		//���� �� �������� ����
	{
		drawBut1();
		drawBut2();
		drawBut3();
		drawBut4();
		drawBut5();
		drawBut6();
		drawGraph();
		drawSomeInfo();
		drawButSteps();
		if (cutting)	//���� ����� ����� - ������ �����
			drawLineCut(curPosX, curPosY);
	}
	else    //���� �������� ����
		drawPathVertex(graph.GetVertListSize());

	drawButPath();

	Sleep(35);	//��� �������� ����������� ��������

	glutSwapBuffers();
}