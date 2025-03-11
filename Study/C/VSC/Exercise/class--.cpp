#include <iostream>
using namespace std;

class test
{
public:
    int num;
    test(int a):num(a){}
    test & operator--()
    {
        num--;
        return *this;
    }
    test operator--(int)
    {
        test temp=*this;
        num--;
        return temp;
    }
};
ostream & operator<<(ostream&cout,const test&e)
{
    cout<<e.num<<endl;
    return cout;
}
void test1()
{
    test e1(0);
    cout<<--e1<<e1<<--(--e1);
}
void test2()
{
    test e2(0);
    cout<<e2--<<e2;
}
int main()
{
    //test1();
    test2();
}