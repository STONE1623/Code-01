/*
题目J：出现频率最高的英文字母
题目描述
请编写程序，找出一段给定文字中出现最频繁的那个英文字母

输入
输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）

输出
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

样例输入 Copy
This is a simple TEST.  There ARE numbers and other symbols 1&2&3
样例输出 Copy
e 7
提示
有多组测试样例 使用while(getline(cin, s)){}*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    string str;
    while(getline(cin,str))
    {
        int zimu[26]={0};
        for(int i=0;i<str.length();i++)
        {
            if(str[i]-65>=0&&str[i]-90<=0)
            {
                zimu[str[i]-65]+=1;
            }
            if(str[i]-97>=0&&str[i]-122<=0)
            {
                zimu[str[i]-97]+=1;
            }
        }
        int max=zimu[0];int maxzimu=0;
        for(int i=0;i<26;i++)
        {
            if(zimu[i]>max) 
            {
                max=zimu[i];
                maxzimu=i;
            }
        }
        cout<<static_cast<char>(maxzimu+97)<<" "<<max<<endl;
    }
}
