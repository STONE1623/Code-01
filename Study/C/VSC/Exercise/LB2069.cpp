#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    double p1=1.0000;int q1=2.0000;
    double sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum+=1.0000*q1/p1;
        q1=p1+q1;
        p1=q1;

    }
    printf("%0.4lf\n",sum);
}