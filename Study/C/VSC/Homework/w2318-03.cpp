#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}

void swap(double &c1,double &d1)
{
    int *c=(int*)(&c1);
    int *d=(int*)(&d1);
    *c=(*c)^(*d);
    *d=(*c)^(*d);
    *c=(*c)^(*d);
    c++;d++;
    *c=(*c)^(*d);
    *d=(*c)^(*d);
    *c=(*c)^(*d);
}
int main()
{
    int a=0,b=0;
    double c=0,d=0;
    while(cin>>a>>b>>c>>d)
    {
        swap(a,b);
        cout<<a<<" "<<b<<" ";
        swap(c,d);
        cout<<c<<" "<<d<<endl;
    }
}