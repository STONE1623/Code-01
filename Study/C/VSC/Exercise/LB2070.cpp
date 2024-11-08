#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double sum=0;double m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            sum+=1.0*1/i;
        }
        else 
        {
            sum-=1.0*1/i;
        }
    }
    cout<<fixed<<setprecision(4)<<sum;
}