#include <iostream>
using namespace std;

class test
{
public:
    int *num;
    test(int a)
    {
        num=new int(a);
    }
    test operator=(const test &e)
    {
        if (num!=NULL)
        {
            delete num;
            num=NULL;
        }
        num=new int(*e.num);
        return *this;
    }
    
};
ostream & operator<<(ostream & cout,const test&e)
{
    cout<<*e.num<<endl;
    return cout;
}
void test1()
{
    test e1(10);
    test e2(20);
    cout<<e1<<e2;
    e1=e2;
    cout<<e1<<e2;

    test e3(30);
    e1=e2=e3;
    cout<<e1<<e2<<e3;
}
int main()
{
    test1();
}