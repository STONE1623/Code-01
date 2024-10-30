#include <iostream>
#include <climits>
#include <cmath>
#define PI 3.1415926
using namespace std;
//求三角函数

double f(double a)
{
    double b=a*PI/180;
    return b;
}
int main()
{
    for(int a=0;a<=180;a+=10)
    {
        cout<<sin(f(a))<<" "<<cos(f(a))<<" "<<tan(f(a))<<endl;
    }
}