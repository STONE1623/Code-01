#include <iostream>
using namespace std;

int main()
{
    int m=0,n=0;
    cin>>n>>m;
    double arr[n][m];
    double arr2[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(i==0||j==0||i==n-1||j==m-1) arr2[i][j]=arr[i][j];
        }
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            arr2[i][j]=int((arr[i-1][j]+arr[i+1][j]+arr[i][j-1]+arr[i][j+1]+arr[i][j])*1.0/5+0.5);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            cout<<arr2[i][j]<<' ';
        }
        cout<<arr2[i][m-1];
        cout<<endl;
    }
    return 0;

}