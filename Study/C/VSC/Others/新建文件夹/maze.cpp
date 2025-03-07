#include"maze.h"
int xStart,yStart,xEnd,yEnd;//�����
int directions[4] = { 0, 1, 2, 3 };//DFS�����Թ�ʱ����������˳��
int flagSuccess = 0;//��¼Ѱ��·�����

void printMaze(char** array, int length, int width) {
	system("pause");
	system("cls");//ÿ��һ���������̨

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			cout << array[i][j]<<' ';
		}
		cout << endl;
	}
	cout << "�������Ϊ����" << xStart + 1 << "��,��" << yStart + 1 << "��" << endl;
	cout << "��������Ϊ����" << xEnd + 1 << "��,��" << yEnd + 1 << "��" << endl;
}


// ����������������Թ�
void dfsGenerate(char** maze, int x, int y, int length, int width) {
	// ���巽������
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1, 0 };
	
	srand((unsigned)time(NULL));
	// ������ҷ���˳��
	for (int i = 0; i < 4; ++i) {
		int randIndex = rand() % 4;
		int temp = directions[i];
		directions[i] = directions[randIndex];
		directions[randIndex] = temp;
	}

	for (int i = 0; i < 4;i++) {
		int nx = x + dx[directions[i]] * 2;//�ҵ���һ���������
		int ny = y + dy[directions[i]] * 2;
		if (nx > 0 && nx < length - 1 && ny > 0 && ny < width - 1 && maze[ny][nx] == '#') {
			maze[ny][nx] = '.';
			maze[y + dy[directions[i]]][x + dx[directions[i]]] = '.';//��ԭ���ĵ�����ѡȡ�ĵ��ͨ
			dfsGenerate(maze, nx, ny, length, width);
		}
	}
}


void mazeGenerator(char** array, int length, int width) {
	// ��ʼ���Թ���ȫ����Ϊǽ
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < width; ++j) {
			array[j][i] = '#';
		}
	}

	// ���ѡ��һ�����
	int startX = rand() % ((length - 1) / 2) * 2 + 1;
	int startY = rand() % ((width - 1) / 2) * 2 + 1;
	array[startY][startX] = '.';

	// ��ʼDFS�����Թ�
	dfsGenerate(array, startX, startY, length, width);

	//���濪ʼ���ɳ����
	int aStart = rand() % (4), bStart = 0;//aStart��ʾ����һ��ǽ bStart��ʾ�ھ���ڼ��� �ȳ�ʼ��
	switch (aStart) {
	case 0: {//������Ϸ�
		bStart = rand() % (length);
		array[0][bStart] = '.';
		yStart = 0, xStart = bStart;
		break;
	}
	case 1: {//������ҷ�
		bStart = rand() % (width);
		array[bStart][length - 1] = '.';
		yStart = bStart, xStart = length - 1;
		break;
	}
	case 2: {//������·�
		bStart = rand() % (length);
		array[width - 1][bStart] = '.';
		yStart = width - 1, xStart = bStart;
		break;
	}
	case 3: {//�������
		bStart = rand() % (width);
		array[bStart][0] = '.';
		yStart = bStart, xStart = 0;
		break;
	}
	}
	//�������

	int aEnd = rand() % (4), bEnd = 0;
	do{
		switch (aEnd) {
		case 0: {
			bEnd = rand() % (length);
			array[0][bEnd] = '.';
			yEnd = 0, xEnd = bEnd;
			break;
		}
		case 1: {
			bEnd = rand() % (width);
			array[bEnd][length - 1] = '.';
			yEnd = bEnd, xEnd = length - 1;
			break;
		}
		case 2: {
			bEnd = rand() % (length);
			array[width - 1][bEnd] = '.';
			yEnd = width - 1, xEnd = bEnd;
			break;
		}
		case 3: {
			bEnd = rand() % (width);
			array[bEnd][0] = '.';
			yEnd = bEnd, xEnd = 0;
			break;
		}
		}
	}
	while (aStart == aEnd && bStart == bEnd);//����������ͬ�����·������
}


void mazeTraverse(char**arr1,int**arr2,int length,int width,int x,int y) {
	if (x == xEnd && y == yEnd) {
		flagSuccess = 1;
		return;
	}

	int xMove[4] = {1,0,-1,0};
	int yMove[4] = {0,1,0,-1};//DFS�����ķ�������
	for (int i = 0; i < 4; i++) {
		int xTemp = x+xMove[i];
		int yTemp = y+yMove[i];
		if ((xTemp >= 0 && xTemp < length) && (yTemp >= 0 && yTemp < width)&&flagSuccess==0)
		if (arr1[yTemp][xTemp] == '.' && arr2[yTemp][xTemp] == 0) {
			arr2[yTemp][xTemp] = 1;
			arr1[yTemp][xTemp] = 'X';//�߹���·��ʶ
			printMaze(arr1, length, width);
			mazeTraverse(arr1, arr2, length, width, xTemp, yTemp);

			if(flagSuccess==0){
				arr2[yTemp][xTemp] = 0;
				arr1[yTemp][xTemp] = '.';//����
				printMaze(arr1, length, width);
			}
		}
	}
}