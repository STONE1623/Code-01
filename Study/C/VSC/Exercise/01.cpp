#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int n,m,s,d;
    s=0;d=0;
    cin>>n;
    while(cin>>m)
    {
        s+=m;
        d++;
        if(d==n) break;
    }
    double a=1.000*s/n;
    cout<<s<<" "<<setprecision(5)<<a;
}