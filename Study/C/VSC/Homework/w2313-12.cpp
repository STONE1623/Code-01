#include <iostream>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        const int N=n;
        int a[N],b[N];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        for(int j=0;j<n;j++)
        {
            a[j]=b[n-j-1];
        }
        for(int k=0;k<n-1;k++)
        {
            cout<<b[k]<<" ";
        }
        cout<<b[n-1]<<endl;
        for(int k=0;k<n-1;k++)
        {
            cout<<a[k]<<" ";
        }
        cout<<a[n-1]<<endl;
    }
}