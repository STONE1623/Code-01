#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    double h,m,sum;
    int i;
    while(cin>>h>>m)
    {
        i=1;
        sum=h;
        while(1)
        {
            if(h>=0.1) {h=h*m;i++;;sum+=h;}
            else {break;}
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
        cout<<i<<endl; 
    }
}