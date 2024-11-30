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
    int matrix[224][224]={0};
    while(cin>>x>>y>>d){
    int sum=0;
    for(int i=0;i<223;i++)
    {

        for(int j=0;j<223;j++)
        {
            matrix[i][j]=D4(x,y,i,j);//cout<<matrix[i][j]<<" ";

        }
        for(int j=0;j<223;j++)
        {
            if(matrix[i][j]<=d)
            {
                sum+=(i+j)%2;
            }
        }
        cout<<" ";cout<<sum<<endl;

    }
            //cout<<sum<<endl;
    }
}