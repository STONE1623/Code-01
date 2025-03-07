#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <iostream>
#define MAX_SIZE 100
void mazeGenerator(int M, int N, char maze[MAX_SIZE][MAX_SIZE], int *entranceRow, int *exitRow) 
{
    for (int i = 0; i < M; ++i) 
	{
        for (int j = 0; j < N; ++j) 
		{
            maze[i][j] = '#';
        }
    }
    srand(time(NULL));
    *entranceRow = rand() % M;
    *exitRow = rand() % M;
    maze[*entranceRow][0] = '.';
    maze[*exitRow][N - 1] = '.';
    int stackX[MAX_SIZE * MAX_SIZE];
    int stackY[MAX_SIZE * MAX_SIZE];
    int top = 0;
    stackX[top] = *entranceRow;
    stackY[top] = 0;
    top++;
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    visited[*entranceRow][0] = 1;
    while (top > 0) 
	{
        int x = stackX[top - 1];
        int y = stackY[top - 1];
        int neighborCount = 0;
        int neighborX[4];
        int neighborY[4];
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) 
		{
            int nx = x + 2 * dx[i];
            int ny = y + 2 * dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny]) 
			{
                neighborX[neighborCount] = nx;
                neighborY[neighborCount] = ny;
                neighborCount++;
            }
        }
        if (neighborCount > 0) 
		{
            int randomIndex = rand() % neighborCount;
            int nextX = neighborX[randomIndex];
            int nextY = neighborY[randomIndex];
            int mx = (x + nextX) / 2;
            int my = (y + nextY) / 2;
            maze[mx][my] = '.';
            maze[nextX][nextY] = '.';
            visited[nextX][nextY] = 1;
            stackX[top] = nextX;
            stackY[top] = nextY;
            top++;
        } 
		else 
		{
            top--;
        }
    }
}
void printMaze(int M, int N, char maze[MAX_SIZE][MAX_SIZE], int entranceRow, int exitRow) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == entranceRow && j == 0) {
                printf("A");
            } else if (i == exitRow && j == N - 1) {
                printf("B");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
int mazeTraverse(int M, int N, char maze[MAX_SIZE][MAX_SIZE], int x, int y, int entranceX, int entranceY, int exitRow) {
    if (x != entranceX || y != entranceY) {
        maze[x][y] = 'X';
    }
    printMaze(M, N, maze, entranceX, exitRow);
    if (x == exitRow && y == N - 1) {
        printf("succeed to exit\n");
        return 1;
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; ++i) 
	{
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && (maze[nx][ny] == '.' || (nx == exitRow && ny == N - 1))) 
		{
            if (mazeTraverse(M, N, maze, nx, ny, entranceX, entranceY, exitRow)) 
			{
                return 1;
            }
        }
    }
    if (x != entranceX || y != entranceY) 
	{
        maze[x][y] = '.';
    }
    if (x == entranceX && y == entranceY) 
	{
        printf("return to the entrance\n");
    }
    return 0;
}
int main()
{
    int M, N;
    char maze[MAX_SIZE][MAX_SIZE];
    int entranceRow, exitRow;
    printf("please give the length(less than 100): ");
    scanf("%d", &M);
    cout<<" ";
    printf("please give the width(less than 100): ");
    scanf("%d", &N);
    cout<<" ";
    mazeGenerator(M, N, maze, &entranceRow, &exitRow);
    printMaze(M, N, maze, entranceRow, exitRow);
    mazeTraverse(M, N, maze, entranceRow, 0, entranceRow, 0, exitRow);
    return 0;
}