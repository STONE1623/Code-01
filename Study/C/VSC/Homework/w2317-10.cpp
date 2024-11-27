#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        const int M=m,N=n;
        bool mat[M][N];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            cin>>mat[i][j];
        }
        int degree=0;
        cin>>degree;
        if(degree==90)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=m-1;j>0;j--) cout<<mat[j][i]<<" ";
                cout<<mat[0][i]<<endl;
            }
        }
        if(degree==180)
        {
            for(int i=m-1;i>=0;i--)
            {
                for(int j=n-1;j>0;j--) cout<<mat[i][j]<<" ";
                cout<<mat[i][0]<<endl;
            }
        }
        if(degree==270)
        {
            for(int i=n-1;i>=0;i--)
            {
                for(int j=0;j<m-1;j++) cout<<mat[j][i]<<" ";
                cout<<mat[m-1][i]<<endl;
            }
        }
    }
}