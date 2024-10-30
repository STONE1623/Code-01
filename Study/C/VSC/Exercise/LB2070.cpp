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
        sum+=1.0*pow(-1.0,n+1)*1/n;
    }
    cout<<fixed<<setprecision(4)<<sum;
}