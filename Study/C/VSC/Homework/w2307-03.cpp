#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

double max(double a,double b,double c)
{
    if(a>=b)
    {
        if(a>=c) return a;
        else return c;
    }
    else //a<b
    {
        if(c>=b) return c;
        else return b;
    }
}
double min(double a,double b,double c)
{
    if(a>=b)
    {
        if(b>=c) return c;
        else return b;
    }
    else //a<b
    {
        if(c>=a) return a;
        else return c;
    }
}
int main()
{
    double max(double,double,double);
    double min(double,double,double);
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        cout<<"max = "<<max(a,b,c)<<" min = "<<min(a,b,c)<<endl;
    }
}