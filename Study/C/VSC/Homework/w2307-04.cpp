#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int r(int a,int b)
{
    int r=0;
    if(a==1)
    {
        for(int i=1;i<=b;)
        {
            r=(25173*r+13849)%65536;
            if(r>=1&&r<=9)
            {
                i++;            
            }
            
        }
        return r;
    }
    else if(a==2) //(a==2&&r>=10&&r<=99)
    {
        for(int i=1;i<=b;)
        {
            r=(25173*r+13849)%65536;
            if(r>=10&&r<=99)
            {               
                i++;            
            }
        }
        return r;
    
    }
}
int main()
{
    int r(int,int);
    int w,n;
    while(cin>>w>>n)
    {
        //for(int j=1;j<=n;j++)
        int j=1;
        for(int i=1;i<=n;i++)
        {

            cout<<r(w,j)<<"+"<<r(w,j+1)<<"="<<r(w,j)+r(w,j+1)<<", "<<r(w,j)<<"-"<<r(w,j+1)<<"="<<r(w,j)-r(w,j+1)<<", "<<r(w,j)<<"*"<<r(w,j+1)<<"="<<r(w,j)*r(w,j+1)<<", "<<r(w,j)<<"/"<<r(w,j+1)<<"="<<r(w,j)/r(w,j+1)<<endl;
            
            j+=2;
        }
    }
}