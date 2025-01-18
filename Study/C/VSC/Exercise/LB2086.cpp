#include <iostream>
using namespace std;
//version2
/*int main()
{
    double a=0,b=0,c=0; //y=c/b-a/b *x
    cin>>a>>b>>c;
    int x=0,y=0;double y1=0;
    int num=0;
    for(;x<=c/a;x++)
    {
        y=(c-a*x)/b;
        if(a*x+b*y==c) num++;
    } 
    cout<<num<<endl;
}*/

//version1
#include <iostream>
using namespace std;

int main()
{
    double a=0,b=0,c=0; //y=c/b-a/b *x
    cin>>a>>b>>c;
    double x=0,y=0;double y1=0;
    int num=0;
    for(x=0;x<=c/a;x++)
    {
        y=1.0*c/b-(1.0*a/b)*x;y1=(int)(1.0*c/b-(1.0*a/b)*x);
        if(y==y1&&y>=0&&x>=0){num++;}
    } 
    cout<<num<<endl;
}