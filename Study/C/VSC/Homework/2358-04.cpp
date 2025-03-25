/*问题D:求两直线交点
定义一个表示点的结构类型 Point 和一个由直线方程y=ax十b确定的直线类 Line。 
结构类型 Point有两个成员x和y，分别表示点的横坐标和纵坐标。Line 类有两个数据成员a和b，
分别表示直线方程中的系教。Line 类有一个成员函数 print 用于显示直线方程。
友元函数 setPoint(Line &l1,Line &l2)用于求两条直线的交点。
在 main 两数中，建立两个直线对象，分别调用 print 函数显示两条直线的方程，并调用函数 setPoint求这两条直线的交点。

输入
两条直线的斜率和截距
输出
两条直线的方程和交点*/

#include <iostream>
using namespace std;


class Line
{
public:
    float a;float b;
public:
    void print()
    {
        cout<<"y = "<<a<<"x + "<<b<<endl;
    }
    Line(float c,float d):a(c),b(d) {}
    friend void setPoint(Line &l1,Line &l2);
};
class Point
{
public:
    float x;float y;
    void setPoint(Line &l1,Line &l2);

};
void Point::setPoint(Line &l1,Line &l2)
{
    float c=l1.a-l2.a; //5-1=4
    float d=l2.b-l1.b; //
    float x1;
    if(d==0) x1=0;
    else x1=d/c;
    float y1=l1.a*x1+l1.b;
    x=x1;y=y1;
    cout<<"("<<x<<","<<y<<")"<<endl;
}
int main()
{
    float a;float b;
    while(cin>>a>>b)
    {
        Line l1(a,b);
        l1.print();
        cin>>a>>b;
        Line l2(a,b);
        l2.print();
        Point p;
        p.setPoint(l1,l2);
    }
}