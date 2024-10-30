#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int sum,g,s,c,n,i,g1,s1,c1;
    cin>>n;
    g1=0;s1=0;c1=0;sum=0;
    g=0;s=0;c=0;
    i=1;
    while(cin>>g>>s>>c)
    {
        g1+=g;s1+=s;c1+=c;
        i++;
        if(i>=n+1) break;
    }
    sum=g1+s1+c1;
    cout<<g1<<" "<<s1<<" "<<c1<<" "<<sum;
}