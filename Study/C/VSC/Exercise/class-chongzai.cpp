#include <iostream>
using namespace std;
//类的左移运算符重载
class test
{
public:
    friend ostream & operator<<(ostream &cout,test &t);
    int p1;
    int p2;
    test(int num1,int num2,int num3):p1(num1),p2(num2),p3(num3) {}
    void operator<<(ostream &cout) //ostream类需要加&引用，全局只能有一个cout,
    {
        cout<<p1<<endl;
    }
private:
    int p3;
};

/*void operator<<(ostream &cout,test &t1)
{
    cout<<t1.p2<<endl;
}*/

ostream & operator<<(ostream &cout,test &t) //返回一个引用的cout
{
    cout<<"p2:"<<t.p2<<"p3:"<<t.p3<<endl;
    return cout; //返回cout继续执行cout<<t2;
}
int main()
{
    test t1(10,20,30);
    test t2(40,50,60);
    //1.成员函数
    t1<<cout;
    t1.operator<<(cout);//非简化方法，括号不能省略

    //2.全局函数
    cout<<t1;//可以实现cout在前
    operator<<(cout,t1);
    //cout<<ti<<t2; //出现错误：不满足链式编程法则，cout<<t1没有返回值，无法继续执行后面代码
    cout<<t1<<t2;

    //3.结合友元访问私有成员
    cout<<t2;
}