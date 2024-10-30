#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

double p(double x,double n)
{ 
    if(n==0) return 1;
    else if(n==1) return x;
    else return ((2*n-1)*p(x,n-1)-(n-1)*p(x,n-2))/n;
    
}
int main()
{
    double p(double,double);
    double x;double n;
    while(cin>>x>>n)
    {
        cout<<p(x,n)<<endl;
    }
}