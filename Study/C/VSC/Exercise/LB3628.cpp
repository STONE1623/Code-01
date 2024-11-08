#include <iostream>
#include <climits>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n=0;int a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<=n;j++)
    {
        int p=0;
        for(p=j+1;p<n;p++)
        {
            int num;
            if(a[p]<a[j])
            {
                num=p;
            }
        }
        int t=a[j];
        a[j]=a[p];
        a[p]=t;
    }
    for(int u=0;u<n;u++)
    {
        cout<<a[u]<<" ";
    }
}