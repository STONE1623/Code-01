#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int F(int a)
{
    int x1=1;int x2=1;int x=0;int t;
    if(a==1||a==2) return 1;
    else
    {
        for(int k=3;k<=a;k++)
        {
            x=x1+x2;
            t=x;
            x1=x2;
            x2=x;    
        }
        return x;
    }
}
int main()
{
    int a,n,m;
    n=0;
    cin>>n;
    vector <int> b(n);
    int i=0;
    while(cin>>m)
    {
        b[i]=m;
        i++;
        if(i>=n) break;
    }
    for(int j=0;j<=n-1;j++)
    {
        cout<<F(b[j])<<endl;
    }  
}