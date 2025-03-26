#include <iostream>
#include <cmath>
using namespace std;

class RMB
{
private:
    int yuan;
    int jiao;
    int fen;
    bool mark=1;
public:
    friend istream & operator>>(istream & cin,RMB & a);
    friend ostream & operator<<( ostream & cout,const RMB & a);
    RMB(){}
    RMB(int a,int b,int c,bool d):yuan(a),jiao(b),fen(c) {mark=d;}
    RMB(double a)
    {
        if(a>=0) mark=1;
        else mark=0;
        yuan=abs(a);
        jiao=abs(static_cast<int>((a-yuan)*10)%10);
        fen=abs(static_cast<int>((a-yuan)*100)%10);
    }
    operator double() const
    {
        double a;
        a=yuan+0.1*jiao+0.01*fen;
        if(mark==0) a*=(-1);
        return a;
    }
    /*RMB operator+(const RMB & a) const
    {
        
        if(a.mark==1)
        {
            double c=double(const *this);double b=double(a);
            RMB temp(c+a);
            return temp;
            temp.yuan=yuan+a.yuan;
            temp.jiao=jiao+a.jiao;
            temp.fen=fen+a.fen;
            temp.mark=1;
        }
        else
        {
            double c=double(const *this);double b=double(a);
            RMB temp(c-a);
            return temp;
            temp.yuan=yuan-a.yuan;
            temp.jiao=jiao-a.jiao;
            temp.fen=fen-a.fen;
            temp.mark=1;
        }
        
    }*/

};
istream & operator>>(istream & cin,RMB & a)
{
    cin>>a.yuan>>a.jiao>>a.fen;
    return cin;
}
ostream & operator<<( ostream & cout,const RMB & a)
{
    if(a.mark==0) 
    {
        cout<<"-";
        cout<<a.yuan<<"元"<<a.jiao<<"角"<<a.fen<<"分"<<endl;
        return cout;
    }
    cout<<a.yuan<<"Y"<<a.jiao<<"J"<<a.fen<<"F"<<endl;
    return cout;
}


/*
RMB(double a)
{
    RMB temp;
    if(a>=0) temp.mark=1;
    else temp.mark=0;
    temp.yuan=abs(a);
    temp.jiao=abs(static_cast<int>((a-yuan)*10)%10);
    temp.fen=abs(static_cast<int>((a-yuan)*100)%10);
    return temp;
}*/
int main()
{
    RMB a, b; 
        double c; 
        while(cin >> a){  
            //cout <<"b:\n"; 
            cin >> b; 
            //cout <<"c:\n"; 
            cin >> c;
            cout<<c<<endl;
            RMB temp(c);
            cout << "a = "<< a << "b = " << b << "c = " <<temp; 
            double a1=double(a);double c1=double(c)+a1;RMB temp2(c1);
            cout << "a + c = " << temp2; 
            c1=a1-double(b);
            RMB temp3(c1);
            cout << "a - b = " << temp3;  
            double b1=double(b)*2;
            RMB temp4(b1);
            cout << "b * 2 = " << temp4;  
            RMB temp5(a1*0.5);
            cout << "a * 0.5 = " << temp5 ;
     }       
     return 0;
}
