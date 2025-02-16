#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

void initialize(vector<vector<char>>& maze,int m,int n)
{
    for(int i=1;i<2*m;i++)
    {
        for(int j=1;j<2*n;j++)
        {
            if(j%2==1) maze[i][j]='.';
        }
    }
}

void mazeGenerator(vector<vector<char>>& maze,vector<int>& sign,int x,int y,int m,int n)
{
    sign[(y-1)*n+x-1]=1;
    //判断四方向上是否有未访问的店
    int flag1=0,flag2=0,flag3=0,flag4=0; //(y-1)*n+x-1
    if(y>1) {if(sign[(y-2)*n+x-1]==0) flag1=1;} //上
    if(y<m) {if(sign[y*n+x-1]==0) flag2=1;} //下
    if(x>1) {if(sign[(y-1)*n+x-2]==0) flag3=1;}
    if(x<n) {if(sign[(y-1)*n+x]==0) flag4=1;}

    while(flag1+flag2+flag3+flag4>0)
    {
        int vx[4]={1,-1,0,0};
        int vy[4]={0,0,1,-1};
        int nx, ny;
        nx=x+vx[rand()%4];
        ny=y+vy[rand()%4];
        while(1)
        {
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
            {
                if(sign[(ny-1)*n+nx-1]==0) break;
                else
                {
                    nx=x+vx[rand()%4];
                    ny=y+vy[rand()%4];
                }
            }
            else
            {
                nx=x+vx[rand()%4];
                ny=y+vy[rand()%4];
            }
        }

        mazeGenerator(maze,sign,nx,ny,m,n);
        if(y>1) {if(sign[(y-2)*n+x-1]==0) flag1=1;} //上
        if(y<m) {if(sign[y*n+x-1]==0) flag2=1;} //下
        if(x>1) {if(sign[(y-1)*n+x-2]==0) flag3=1;}
        if(x<n) {if(sign[(y-1)*n+x]==0) flag4=1;}
    }


}
int main()
{
    srand(time(0));
    //迷宫的长宽
    int m,n; 
    cin>>m>>n;
    //
    vector<vector<char>> maze(2*m+1,vector<char>(2*n+1,'#'));
    vector<int> sign(m*n,0); //0:未访问 1:已访问
    initialize(maze,m,n);

    /*for(int i=0;i<2*m+1;i++)
    {
        for(int j=0;j<2*n+1;j++) cout<<maze[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    mazeGenerator(maze,sign,1,1,m,n);
    for(int i=0;i<2*m+1;i++)
    {
        for(int j=0;j<2*n+1;j++) cout<<maze[i][j]<<" ";
        cout<<endl;
    }
}