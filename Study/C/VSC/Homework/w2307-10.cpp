#include <iostream>
using namespace std;

long Multi(int m,int n)
{
    long sum=m;
    for(int i=1;i<=m-n;i++)
    {
        sum*=(m-i);
    }
    return sum;
}
long Fabricate(int m,int n)
{
    long a=Multi(m,1);long b=Multi(n,1);long c=Multi(m-n,1);
    long sum1=1;
    sum1=a/(b*c);
    return sum1;
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        //cout<<Multi(m,n)<<endl;
        cout<<Fabricate(m,n)<<endl;
    }
}