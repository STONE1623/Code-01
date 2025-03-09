#include <iostream>
using namespace std;
//静态成员函数
class test
{
public:
    int num1;
    static int num2;
    static void fun()
    {
        //num1=10; //无法执行：不知道是哪个的num1变量
        num2=10;
    }
}