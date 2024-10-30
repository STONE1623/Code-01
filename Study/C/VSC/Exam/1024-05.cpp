#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int va,vb,bp,d;
    float i;
    float t;
    while(cin>>vb>>va>>bp>>t)
    {
        d=bp+vb*t-va*t;
        if(d<=0)
        {
            cout<<"keyi"<<endl;
            i=0;
            int k=bp+vb*i-va*i;
            while(k>0)
            {
                i+=0.000001;
                k=bp+vb*i-va*i;
                if(k<=0) break;
            }
            
            cout<<fixed<<setprecision<<i;
            break;
        }
        if(d>0) cout<<"飞船A无法追上飞船B"<<endl;
    }
}