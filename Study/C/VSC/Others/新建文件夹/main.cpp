#include"maze.h"

int main() {
	char again = '0';

	do{
		cout << "�������Թ��ĳ��Ϳ����Թ��������Ϊ����,������ô��ڵ���5��" << endl;
		int M = 0, N = 0;
		cin >> M >> N;
		while (M < 5 || N < 5) {
			cout << "���볤�ȹ�С������������" << endl;
			cin >> M >> N;
		}
		cout << "�Թ��ĳ�Ϊ" << M << ';' << "�Թ��Ŀ�Ϊ" << N << endl;

		char** arrayMaze = new char* [N];
		for (int i = 0; i < N; i++)
			arrayMaze[i] = new char[M];
		int** arrayVisit = new int* [N];
		for (int i = 0; i < N; i++)
			arrayVisit[i] = new int[M]();

		mazeGenerator(arrayMaze, M, N);
		//�����Թ�

		printMaze(arrayMaze, M, N);
		//��ӡ�Թ�

		arrayVisit[yStart][xStart] = 1;
		arrayMaze[yStart][xStart] = 'X';
		//������߳���һ��

		printMaze(arrayMaze, M, N);//��ӡ��һ��չʾ���

		mazeTraverse(arrayMaze, arrayVisit, M, N, xStart, yStart);
		//��ʼ��ʽ��

		if (flagSuccess == 1)
			cout << "�ɹ��߳��Թ�" << endl;
		else
			cout << "���˵����" << endl;
		cout << endl;

		flagSuccess = 0;
		for (int i = 0; i < N; i++)
			delete[] arrayMaze[i];
		delete[] arrayMaze;
		for (int i = 0; i < N; i++)
			delete[] arrayVisit[i];
		delete[] arrayVisit;

		cout << "��Ҫ����һ����" << endl;
		cout << "1:����һ��" << endl;
		cout << "0:�˳�" << endl;
		cin >> again;
		system("cls");

		while (again != '1' && again != '0') {
			cout << "������'1'��'0'" << endl; 
			cin >> again;
		}
	}
	while (again);
	cout << "��ӭ�´�ʹ��" << endl;
	return 0;
}