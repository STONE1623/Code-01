#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        double x1=a/2;   
        double x2=0;
        while(abs(x2-x1)>1e-8)
        {
            x2=x1;
            x1=(x1+a/x1)/2;
        }
        cout<<setprecision(6)<<x1<<endl;
    }
    return 0;
}