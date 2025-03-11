#include <iostream>
using namespace std;

class test
{   
public:
    int num;
    test(int a):num(a){}
    test & operator++()
    {
        num++;
        return *this;
    }
    test operator++(int) //int占位，系统识别为后置++运算
    //后置++返回的非引用，而是值
    {
        test temp=*this;
        num++;
        return temp;
    }
};
ostream & operator<<(ostream& cout,const test&e) 
//注意需要加const：后置++返回临时对象（右值），非const引用无法绑定到右值
{
    cout<<e.num<<endl;
    return cout;
}
//前置++

void test1()
{
    test e1(0);
    cout<<++e1<<e1;
    cout<<++(++e1);
}
void test2()
{
    test e2(0);
    cout<<e2++;
}
int main()
{
    test1();
    test2();
}