#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int m,n,x,y,sum,s;   //x:+    y:-
    while(cin>>m>>n)
    {
        y=n;
        if(n>=m) cout<<"1"<<endl;
        else
        for(int d=2,sum=n;;d++)
        {
            y/=3;
            sum+=y;
            if(sum>=m) {cout<<d<<endl;break;}
            else sum-=1;
            if(sum<=0) {cout<<"Never"<<endl;break;}

        }
    }
}