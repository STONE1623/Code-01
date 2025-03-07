#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
ll m,n,startx,starty,endx,endy,flag=1,t1,t2;
bool check(ll x,ll y)
{
	return x>=0&&x<m&&y>=0&&y<n;
}
void dig(vector<vector<char>> &maze)
{
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			ll k = rand() % 4;
			if (k % 2 == 0) maze[i][j] = '.';
		}
	}
	maze[startx][starty] = '.';
	maze[endx][endy] = '.';
}
vector<vector<char>> createmaze(ll m,ll n,ll startx,ll starty,ll endx,ll endy)
{
	vector<vector<char>>maze(m,vector<char>(n,'#'));
	dig(maze);
	return maze;
}
void printmaze(vector<vector<char>>maze)
{
	for(ll i=0;i<m;++i)
	{
		for(ll j=0;j<n;++j) cout<<maze[i][j];
		cout<<'\n';
	}
}
void dfs(vector<vector<char>>&maze,ll x,ll y)
{
	if(x==endx&&y==endy)
	{
		cout<<"成功走出迷宫"<<'\n';
		flag=0;
		return;
	}
	if(x==startx&&y==starty&&maze[x][y]=='X'&&flag)
	{
		cout<<"回退到入口"<<'\n';
		return;
	}
	else
	{
		if(x==startx&&y==starty)
		{
			maze[x][y]='X';
			printmaze(maze);
		}
		for(ll i=0;i<4;++i)
		{
			if(check(x+dx[i],y+dy[i])&&maze[x+dx[i]][y+dy[i]]=='.'&&flag)
			{
				x+=dx[i];
				y+=dy[i];
				maze[x][y]='X';
				printmaze(maze);
				dfs(maze,x,y);
				if(flag)
				{
					maze[x][y]='.';
					x-=dx[i];
					y-=dy[i];
					printmaze(maze);
				}
				if(x==startx&&y==starty&&maze[x][y]=='X'&&flag)
			    {
			    	cout<<"回退到入口"<<'\n';
			    	return;
			    }
			}
		}
		if(x==startx&&y==starty&&maze[x][y]=='X'&&flag)
		{
			cout<<"回退到入口"<<'\n';
			return;
		}
	}
}
int main()
{
	cin>>n>>m;
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	t1=rand()%(n*m);
	startx=t1/m;
	starty=t1-startx*m;
	t2=rand()%(n*m);
	while(t2==t1)
	{
		t2=rand()%(n*m);
	}
	endx=t2/m;
	endy=t2-endx*m;
	vector<vector<char>>maze=createmaze(m,n,startx,starty,endx,endy);
	dfs(maze,startx,starty);
	return 0;
}
