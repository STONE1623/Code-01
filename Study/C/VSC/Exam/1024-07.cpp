#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int a,b,sum;
    int x[9];int y[9];
    while(cin>>a>>b)
    {
        a[0]=a%10;
        a[1]=a/10%10;
        a[2]=a/100;
        a[3]=a/1000%10;
        a[4]=a/10000%10;
        a[5]=a/100000%10;
        a[6]=a/1000000%10;
        a[7]=a/10000000%10;
        a[8]=a/100000000%10       
        
        
        
        for(int i=0;i<=8;i++)
        {
            a[]
        }
        for(int j=0;j<=8;j++)
        {
            for(int m=0;m<=8;m++)
            {
                sum+=x[j]*y[m];
            }
        }
        cout<<sum+1<<endl;
    }
}