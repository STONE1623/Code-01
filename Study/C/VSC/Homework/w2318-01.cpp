//问题 A: 右移操作验证
/*题目描述
编写程序，将一个整型变量右移 4 位，并以二进制数形式输出该整数在移位前和移位后的数值。观察系统填补空缺位的情况。
输入
一个整数值
输出
移位前的整数值，移位前的二进制值，右移4位的整数值，右移4位的二进制值（一个数据占一行）*/

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int m=0;
    while(cin>>m)
    {
        int m1=m;
        int a;
        cout<<bitset<32>(m);
        cout<<endl;
        m>>=4;
        cout<<m<<endl;
        cout<<bitset<32>(m);
        cout<<endl;
    }
}
