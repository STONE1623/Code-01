#include"maze.h"
int xStart,yStart,xEnd,yEnd;//出入口
int directions[4] = { 0, 1, 2, 3 };//DFS生成迷宫时候用来打乱顺序
int flagSuccess = 0;//记录寻找路径结果

void printMaze(char** array, int length, int width) {
	system("pause");
	system("cls");//每按一次清除控制台

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			cout << array[i][j]<<' ';
		}
		cout << endl;
	}
	cout << "入口坐标为：第" << xStart + 1 << "列,第" << yStart + 1 << "行" << endl;
	cout << "出口坐标为：第" << xEnd + 1 << "列,第" << yEnd + 1 << "行" << endl;
}


// 深度优先搜索生成迷宫
void dfsGenerate(char** maze, int x, int y, int length, int width) {
	// 定义方向数组
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1, 0 };
	
	srand((unsigned)time(NULL));
	// 随机打乱方向顺序
	for (int i = 0; i < 4; ++i) {
		int randIndex = rand() % 4;
		int temp = directions[i];
		directions[i] = directions[randIndex];
		directions[randIndex] = temp;
	}

	for (int i = 0; i < 4;i++) {
		int nx = x + dx[directions[i]] * 2;//找到下一个点的坐标
		int ny = y + dy[directions[i]] * 2;
		if (nx > 0 && nx < length - 1 && ny > 0 && ny < width - 1 && maze[ny][nx] == '#') {
			maze[ny][nx] = '.';
			maze[y + dy[directions[i]]][x + dx[directions[i]]] = '.';//将原来的点与新选取的点打通
			dfsGenerate(maze, nx, ny, length, width);
		}
	}
}


void mazeGenerator(char** array, int length, int width) {
	// 初始化迷宫，全部设为墙
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < width; ++j) {
			array[j][i] = '#';
		}
	}

	// 随机选择一个起点
	int startX = rand() % ((length - 1) / 2) * 2 + 1;
	int startY = rand() % ((width - 1) / 2) * 2 + 1;
	array[startY][startX] = '.';

	// 开始DFS生成迷宫
	dfsGenerate(array, startX, startY, length, width);

	//下面开始生成出入口
	int aStart = rand() % (4), bStart = 0;//aStart表示在哪一面墙 bStart表示在具体第几格 先初始化
	switch (aStart) {
	case 0: {//入口在上方
		bStart = rand() % (length);
		array[0][bStart] = '.';
		yStart = 0, xStart = bStart;
		break;
	}
	case 1: {//入口在右方
		bStart = rand() % (width);
		array[bStart][length - 1] = '.';
		yStart = bStart, xStart = length - 1;
		break;
	}
	case 2: {//入口在下方
		bStart = rand() % (length);
		array[width - 1][bStart] = '.';
		yStart = width - 1, xStart = bStart;
		break;
	}
	case 3: {//入口在左方
		bStart = rand() % (width);
		array[bStart][0] = '.';
		yStart = bStart, xStart = 0;
		break;
	}
	}
	//生成入口

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
	while (aStart == aEnd && bStart == bEnd);//如果出入口相同就重新分配出口
}


void mazeTraverse(char**arr1,int**arr2,int length,int width,int x,int y) {
	if (x == xEnd && y == yEnd) {
		flagSuccess = 1;
		return;
	}

	int xMove[4] = {1,0,-1,0};
	int yMove[4] = {0,1,0,-1};//DFS搜索的方向数组
	for (int i = 0; i < 4; i++) {
		int xTemp = x+xMove[i];
		int yTemp = y+yMove[i];
		if ((xTemp >= 0 && xTemp < length) && (yTemp >= 0 && yTemp < width)&&flagSuccess==0)
		if (arr1[yTemp][xTemp] == '.' && arr2[yTemp][xTemp] == 0) {
			arr2[yTemp][xTemp] = 1;
			arr1[yTemp][xTemp] = 'X';//走过的路标识
			printMaze(arr1, length, width);
			mazeTraverse(arr1, arr2, length, width, xTemp, yTemp);

			if(flagSuccess==0){
				arr2[yTemp][xTemp] = 0;
				arr1[yTemp][xTemp] = '.';//回退
				printMaze(arr1, length, width);
			}
		}
	}
}