/*问题D:求两直线交点
定义一个表示点的结构类型 Point 和一个由直线方程y=ax十b确定的直线类 Line。 
结构类型 Point有两个成员x和y，分别表示点的横坐标和纵坐标。Line 类有两个数据成员a和b，
分别表示直线方程中的系教。Line 类有一个成员函数 print 用于显示直线方程。
友元函数 setPoint(Line &l1,Line &l2)用于求两条直线的交点。
在 main 两数中，建立两个直线对象，分别调用 print 函数显示两条直线的方程，并调用函数 setPoint求这两条直线的交点。
定义setPoint 类，包含两个 Line 类成员和一个表示直线交点的Point 成员，
并定义类中求直线交点的成员函数。编写每个类相应的成员函数和测试用的主函数。
输入
两条直线的斜率和截距
输出
两条直线的方程和交点*/

#include <iostream>
using namespace std;
#define endl "\n"



class Line
{
public:
    float a;float b;
public:
    void print()
    {
        cout<<"y = "<<a<<"x + "<<b<<"\n";
    }

    Line(float c,float d):a(c),b(d) {}
};
class Point
{
public:
    float x;float y;

};
class setPoint
{
    Line l1;Line l2;
    Point p;
public:
    setPoint(Line la,Line lb,Point pa):l1(la),l2(lb),p(pa) {}
    void cal()
    {
        float c=l1.a-l2.a; //5-1=4
        float d=l2.b-l1.b; //
        float x1;
        if(d==0) x1=0;
        else x1=d/c;
        float y1=l1.a*x1+l1.b;
        p.x=x1;p.y=y1;
        cout<<"("<<p.x<<","<<p.y<<")\n";
    }

};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    float a;float b;
    while(cin>>a>>b)
    {
        Line l1(a,b);
        l1.print();
        cin>>a>>b;
        Line l2(a,b);
        l2.print();
        Point p;setPoint set(l1,l2,p);
        set.cal();
    }
}