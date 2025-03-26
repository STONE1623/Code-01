#include <iostream>
using namespace std;

class Vector
{
public:
    int * vec;
    int num;
    int sum;
    Vector() {}
    Vector(int a)
    {
        num=a;
        vec=new int[a] ;
        for(int i=0;i<a;i++)
        {
            cin>>vec[i];
        }
    }
    Vector(const Vector &c) {
        num = c.num;
        sum = c.sum;
        vec = new int[num];
        for(int i = 0; i < num; i++) {
            vec[i] = c.vec[i];
        }
        cout<<"copy"<<endl;
    }

    void operator=(const Vector &c)
    {
        num=c.num;
        vec=new int[num];
        sum=c.sum;
        for(int i=0;i<num;i++)
        {
            vec[i]=c.vec[i];
        }
    }
    Vector operator+(Vector &b)
    {
        Vector temp;
        temp.num=num;
        temp.vec=new int[num];
        for(int i=0;i<num;i++)
        {
            temp.vec[i]=vec[i]+b.vec[i];
        }
        return temp;
    }
    Vector operator-(Vector &b)
    {
        Vector temp;
        temp.num=num;
        temp.vec=new int[num];
        for(int i=0;i<num;i++)
        {
            temp.vec[i]=vec[i]-b.vec[i];
        }
        return temp;
    }
    Vector operator*(Vector &b)
    {
        Vector temp;
        temp.sum=0;
        temp.num=1;
        temp.vec=new int[1];
        temp.vec[0]=1;
        for(int i=0;i<num;i++)
        {
            temp.sum+=(vec[i])*(b.vec[i]);
        }
        return temp;
    }
    ~Vector() {
        delete[] vec;
    }

    friend ostream & operator<<(ostream & cout,const Vector & c);
};
ostream & operator<<(ostream & cout,const Vector & c)
{
    if(c.num!=1){
    cout<<"(";
    for(int i=0;i<c.num-1;i++)
    {
        cout<<c.vec[i]<<",";
    }
    cout<<c.vec[c.num-1]<<")";
    cout<<endl;}
    else
    cout<<c.sum<<endl;
    return cout;
}
int main()
{
    int a,b;
    while(cin>>a){
    Vector v1(a);
    cin>>b;
    Vector v2(b);
    if(b!=a)
    {
        cout<<"error\n";
    }
    else{
    cout<<"X="<<v1<<"Y="<<v2;
    Vector v3=v1+v2;
    cout<<"X+Y="<<v3;
    v3=v1-v2;
    cout<<"X-Y="<<v3;
    v3=v1*v2;
    cout<<"X*Y="<<v3;
    v3.sum=0;}
    
    }
}