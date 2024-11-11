#include <iostream>
using namespace std;

void fun(int n)
{
    const int N=n;int sum=0;
    int a[N][N];
    int b[N-2][N-2];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++) a[i][j]=i-j+1;
        for(int j=i;j<N;j++) a[i][j]=1;
    }

    for(int i=0;i<N-2;i++) //输出小矩阵
    {
        for(int j=0;j<N-3;j++) cout<<a[i+1][j+1]<<" ";
        cout<<a[i+1][N-2]<<endl;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum+=a[i][j];
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++) cout<<a[i][j]<<" ";
        cout<<a[i][N-1]<<endl;
    }

}
int main()
{
    int n=0;
    while(cin>>n)
    {
        fun(n);
    }
}