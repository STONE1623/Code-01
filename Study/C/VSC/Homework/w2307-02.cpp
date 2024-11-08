#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    k1:int m,n,p=0;
    while(cin>>m>>n>>p)
    {
        int sum1=0;
        int sum2=0;
        double sum3=0;
        for(int i=1;i<=m;i++)
        {
            sum1+=i;
            if(sum1>=2147483646||sum1<=-2147483648)
            {
                cout<<"溢出"<<endl;
                goto k1;
            }
        }
        
        for(double k=1;k<=n;k++)
        {
            sum1+=pow(k,3);
            if(sum1>=2147483646||sum1<=-2147483648)
            {
                cout<<"溢出"<<endl;
                goto k1;
            }
        }
        for(double j=1;j<=p;j++)
        {
            sum2+=pow(j,5);
            if(sum2>=2147483646||sum2<=-2147483648)
            {
                cout<<"溢出"<<endl;
                goto k1;
            }
        }
        sum3=1.0*sum1/sum2;
        cout<<sum3<<endl;
    }
}