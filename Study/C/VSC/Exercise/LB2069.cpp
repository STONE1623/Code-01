#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

//qi+1=qi+pi;Pi+1=qi;
int main()
{  
    int n,p,q;
    p=1;q=2;
    double d,sum;
    sum=0;
    cin>>n;
    int t;
    for(int i=1;i<=n;i++)
    {
        sum+=1.0*q/p;
        t=q;
        q=q+p;
        p=t;
    }
    cout<<fixed<<setprecision(4)<<sum<<endl;






    /*double p1=1.0000;int q1=2.0000;
    double sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum+=1.0000*q1/p1;
        q1=p1+q1;
        p1=q1;

    }
    printf("%0.4lf\n",sum);*/
}