#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int x,y,z,a,b,a1,b1,a2,b2=0;
    
    for(x=0;x<=9;x++)
    {
        for(y=0;y<=9;y++)
        {
            a=x*100+y*10+z;
            b=y*100+z*10+z;
            a1=x*100+y*10+1;
            b1=y*100+11;
            a2=x*100+y*10+6;
            b2=y*100+66;

            if(a1+b1==532)
            {
                z=1;
                goto k;
            }
            if(a2+b2==532)
            {
                z=6;
                goto k;
            }
        }
    }
    k:cout<<"x="<<x<<endl<<"y="<<y<<endl<<"z="<<z<<endl;
    return 0;
}