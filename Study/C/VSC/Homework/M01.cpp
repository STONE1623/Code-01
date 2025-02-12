#include <iostream>
using namespace std;

void initialize(int arr[][100], int m, int n) // 假设最大列数为100
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) arr[i][j] = 1; // 初始化数组
    }
    for (int i = 0; i < n; i++) arr[0][i] = 0;
    for (int i = 0; i < n; i++) arr[m - 1][i] = 0;
    for (int i = 1; i < m - 1; i++) arr[i][0] = 0;
    for (int i = 1; i < m - 1; i++) arr[i][n - 1] = 0;
}

void mazeGenerator(int arr[][100],int x,int y,int m,int n)
{
    if(x==0||y==0||x==m-1||y==n-1) return;
    if(arr[x][y]==1) return;
    arr[x][y]=1;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(nx>=0&&nx<m&&ny>=0&&ny<n)
        {
            mazeGenerator(arr,nx,ny,m,n);
        }
    }
}

int main()
{
    int m, n;int x,y;
    cin >> m >> n;
    int arr[100][100]; // 假设最大行数和列数为100
    initialize(arr, m, n);
    cin>>x>>y;
    mazeGenerator(arr,x,y,m,n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}