#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        double s[100];double sum=0;double ave=0;double dev=0;double a=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            sum+=s[i];
        }
        ave=1.0*sum/n;
        for(int j=0;j<n;j++)
        {
            a+=(s[j]-ave)*(s[j]-ave);
        }
        a=1.0*a/n;
        dev=sqrt(a);
        cout<<ave<<" "<<dev<<endl;
        continue;
    }
}