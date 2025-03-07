#include"maze.h"

int main() {
	char again = '0';

	do{
		cout << "请输入迷宫的长和宽：（迷宫长宽最好为奇数,长度最好大于等于5）" << endl;
		int M = 0, N = 0;
		cin >> M >> N;
		while (M < 5 || N < 5) {
			cout << "输入长度过小，请重新输入" << endl;
			cin >> M >> N;
		}
		cout << "迷宫的长为" << M << ';' << "迷宫的宽为" << N << endl;

		char** arrayMaze = new char* [N];
		for (int i = 0; i < N; i++)
			arrayMaze[i] = new char[M];
		int** arrayVisit = new int* [N];
		for (int i = 0; i < N; i++)
			arrayVisit[i] = new int[M]();

		mazeGenerator(arrayMaze, M, N);
		//生成迷宫

		printMaze(arrayMaze, M, N);
		//打印迷宫

		arrayVisit[yStart][xStart] = 1;
		arrayMaze[yStart][xStart] = 'X';
		//丛入口走出第一步

		printMaze(arrayMaze, M, N);//打印第一步展示入口

		mazeTraverse(arrayMaze, arrayVisit, M, N, xStart, yStart);
		//开始正式走

		if (flagSuccess == 1)
			cout << "成功走出迷宫" << endl;
		else
			cout << "回退到入口" << endl;
		cout << endl;

		flagSuccess = 0;
		for (int i = 0; i < N; i++)
			delete[] arrayMaze[i];
		delete[] arrayMaze;
		for (int i = 0; i < N; i++)
			delete[] arrayVisit[i];
		delete[] arrayVisit;

		cout << "还要再来一次吗？" << endl;
		cout << "1:再来一次" << endl;
		cout << "0:退出" << endl;
		cin >> again;
		system("cls");

		while (again != '1' && again != '0') {
			cout << "请输入'1'或'0'" << endl; 
			cin >> again;
		}
	}
	while (again);
	cout << "欢迎下次使用" << endl;
	return 0;
}