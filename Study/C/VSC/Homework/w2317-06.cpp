#include <iostream>
#include <cmath>
using namespace std;

int D4(int x,int y,int s,int t)
{
    int i=0;
    i=abs(x-s)+abs(y-t);
    return i;
}
int main()
{
    int x=0,y=0,d=0;
    int matrix[10][10]={0};
    while(cin>>x>>y>>d){
    int sum=0;
    for(int i=0;i<10;i++)
    {

        for(int j=0;j<10;j++)
        {
            matrix[i][j]=D4(x,y,i,j);//cout<<matrix[i][j]<<" ";
            if(matrix[i][j]<=d) sum+=(i+j)%2;cout<<sum<<endl;
        }
        cout<<endl;

    }
            cout<<sum<<endl;
    }
}