#include <iostream>
#include <climits>
#include <cmath>
#include <math.h>
using namespace std;
typedef double FT(double);
FT f1,f2,f3;
//double t()
double f1(/*double a,double b,*/double x)
{
    //double a=1;int b=0;
    return 4/(1+x*x);
}
double f2(/*double a,double b,*/double x)
{
    //double a=2;int b=1;
    return sqrt(1+x*x);
}
double f3(/*double a,double b,*/double x)
{
    //double a=M_PI/2;
    return sin(x);
}
double t(double a,double b,FT* pFT)
{
    double result;
    double h = (b - a) / 10000;result = 0;
	for (int i = 1; i <= 9999; i++) result += pFT(a + i * h);
	result *= h;
	result += h * (pFT(a) + pFT(b)) / 2;
	return result;


    /*double h=(b-a)/10000;
    double m;double sum=0;
    m=(h*pFT(a)+pFT(b))/2;
    for(int i=1;i<=9999;i++)
    {
        sum+=pFT(a+i*h);
    }
    double r=h+m;
    return r;
    */
}

int main()
{
    /*typedef double FT(double);
    FT *g1,*g2,*g3;
    g1=f1;g2=f2;g3=f3;*/
    cout<<t(0,1,f1)<<" "<<t(1,2,f2)<<" "<<t(0,M_PI/2,f3);
}