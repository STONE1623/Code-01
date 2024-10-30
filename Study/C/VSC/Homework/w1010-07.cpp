#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int m=100;
    int a,b,c=0;
    /*for(int m=100;m<=999;m++)
    {
        a=m+1/100;
        b=m/10%10;
        c=m%10;
        int d=a^3+b^3+c^3;
        if(m==d) cout<<m<<endl;
    }*/

    do
    {
        a=m+1/100;
        b=m/10%10;
        c=m%10;
        int d=a*a*a+b*b*b+c*c*c;
        if(m==d) cout<<m<<endl;
        m++;
    } while (m<1000);
    
    return 0;
}