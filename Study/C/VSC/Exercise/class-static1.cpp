#include <iostream>
using namespace std;

/*总结：
1.c++中，静态成员需要再类内声明，再类外定义，在类内定义无法运行
2.静态成员也区分私有和公有，私有的要通过成员函数定义
3.可以通过内联静态成员直接在声明时直接赋值，如inline static int value = 10
4.必须给静态成员定义方可使用，不会自动赋值为零;*/
class test01
{
private:
    static int A;
public:
    static int B;
    static int C;
    static int D;
    void out()
    {
        cout<<A<<endl;
    }
    void getA(int num)
    {
        A=num;
    }
};

int test01::A = 0;
int test01::B = 0;

void dotest01()
{
    test01 a;
    //a.A=5;
    //cout<<a.A<<endl;
    a.getA(5);
    a.out();
}
void dotest02()
{
    test01::B=1;
    cout<<test01::B<<endl;
}
void dotest03()
{
    test01 a;
    test01::B=2;
    cout<<a.B<<endl;
}
/*void dotest04()
{
    cout<<test01::C<<endl;
}*/
void dotest05()
{
    cout<<test01::D<<endl;//不可在类内定义
}
int main()
{
    dotest01();
    dotest02();
    dotest03();
    /*dotest04();*/
    dotest05();
    return 0;
}