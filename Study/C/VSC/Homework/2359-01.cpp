#include <iostream>
using namespace std;

class Interger
{
public:
    int num;
    Interger() {}
    Interger(int a):num(a) {}
    Interger operator+(Interger & Int2)
    {
        Interger temp;
        temp.num=num+Int2.num;
        return temp;
    }
    Interger operator-(Interger & Int2)
    {
        Interger temp;
        temp.num=num-Int2.num;
        return temp;
    }
    Interger operator*(Interger & Int2)
    {
        Interger temp;
        temp.num=num*Int2.num;
        return temp;
    }
    Interger operator/(Interger & Int2)
    {
        Interger temp;
        if(Int2.num!=0) temp.num=num/Int2.num;
        else temp.num=0;
        return temp;
    }
    void iprint()
    {
        if(num>=-32768&&num<=32767) cout<<num<<endl;
        else cout<<"Data Overflow!"<<endl;
    }
};
int main()
{
    char mark;
    int i1,i2;
    while(cin>>i1>>i2>>mark)
    {
        Interger I1(i1);Interger I2(i2);Interger I3(0);
        if(mark=='+')
        {
            I3=I1+I2;
            I3.iprint();
        }
        else if(mark=='-')
        {
            I3=I1-I2;
            I3.iprint();
        }
        else if(mark=='*')
        {
            I3=I1*I2;
            I3.iprint();
        }
        else
        {
            I3=I1/I2;
            I3.iprint();
        }
    }
}