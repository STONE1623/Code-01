#include <iostream>
#include <climits>
#include <cmath>
#include <math.h>
using namespace std;

void f(double a,double b,double c)
{
    if(a>=b)
    {
        if(b>=c) cout<<a<<" "<<b<<" "<<c<<" ";
        else if(a>=c) cout<<a<<" "<<c<<" "<<b<<" ";
        else cout<<c<<" "<<a<<" "<<c<<" ";
    }
    else if(a>=c) cout<<b<<" "<<a<<" "<<c<<" "; //b>a c
    else if(b>=c) cout<<b<<" "<<c<<" "<<a<<" ";
    else cout<<c<<" "<<b<<" "<<a<<" ";
}
void f(double a,double b)
{
    if(a>=b) cout<<a<<" "<<b;
    else cout<<b<<' '<<a;
}
int main()
{
    void f(double,double);
    void f(double,double,double);
    double a,b,c,d,e;
    while(cin>>a>>b>>c>>d>>e)
    {

         f(a,b);
         cout<<endl;
         f(c,d,e);
         cout<<endl;
    }
}