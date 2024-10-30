#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double a,sum,e;sum=0;
    a=0;
    int i=0;
    cin>>n;
    while(cin>>a)
    {
        sum+=a;
        i++;
        if(i==n) break;
    }
    e=sum/n;
    cout<<fixed<<setprecision(4)<<e;
}