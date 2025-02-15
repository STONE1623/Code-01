#include <iostream>
#include <ctime>
using namespace std;

void initialize(int arr[][100], int m, int n) // 假设最大列数为100
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) arr[i][j] = 1; // 初始化数组
    }

}

void mazeGenerator(int arr[][100],int x,int y,int m,int n)
{
    arr[x][y]=0;
    // 方向：左右上下
    int vx[4]={-1,1,0,0};
    int vy[4]={0,0,-1,1};
    // 生成新坐标
    do{
        int nx=vx[rand()%4]+x;
        int ny=vy[rand()%4]+y;
        int flag=0;
        if(nx<0||ny<0||nx>=m||ny>=n) flag=1;
        if(flag==0)
        {
            if(nx==0)
        }
    }
    while(nx<0||ny<0||nx>=m||ny>=n||arr[nx][ny]==1);
    return mazeGenerator(int arr[][100],nx,ny,m,n);

}
int main()
{
    srand(time(0));
    int m, n;int x,y;
    cin >> m >> n;
    int arr[100][100]; // 假设最大行数和列数为100
    initialize(arr, m, n);
    cin>>x>>y;
    arr[x][y]=1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}