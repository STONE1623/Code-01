#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    int n,s,a,i;
    i=1;s=0;
    cin>>n;
    while(i<=n)
    {
        cin>>a;
        int b1,b2,b3,b4;
        b1=a%10;
        b2=a/10%10;
        b3=a/100%10;
        b4=a/1000;
        if(b1-b2-b3-b4>=0)
        {
            s+=1;
        }
        i++;
    }
    cout<<s<<endl;
}