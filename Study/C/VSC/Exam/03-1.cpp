#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <climits>
using namespace std;
int run4_YorN(int);
int main()
{
    int y, m, d, N, n, j;
    y=2024;
    m=10;
    d=24;
    /*register*/ int i;

    //scanf("%d %d %d", &y, &m, &d);
    while(scanf("%d", &N))
    {
    int    run4[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//闰年数组
    int    ping2[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//平年数组

    n = N + d - 1;//m月d日后N天就等于m月1号后N+d-1天，所以相当于输入y m 1和N+d-1，这种表达更一般
    d = 1;            //简化问题

    for (i = m; i <= 12; i++)
    {
        switch (run4_YorN(y))
        {
        case 1:
            n = n - run4[i - 1];//扣掉当月的天数以后日期应该来到了下个月的1号，此时1号后n天应该是来到了当月的n+1号
            break;
        case 0:
            n = n - ping2[i - 1];
            break;
        }
        if (n < 0)//n=0意味着什么？意味着日期来到了下个月1号，月份i需要+1，所以此处不能是n<=0
            break;
    }                //做完当年的计算

    while (n >= 0)
    {
        y++;
        for (i = 1; i <= 12; i++)
        {
            switch (run4_YorN(y))
            {
            case 1:
                n = n - run4[i - 1];
                break;
            case 0:
                n = n - ping2[i - 1];
                break;
            }
            if (n <= 0)
                break;
        }
    }

    switch (run4_YorN(y))
    {
    case 1:
        j = n + run4[i - 1];
        break;
    case 0:
        j = n + ping2[i - 1];
        break;
    }

    printf("%d年%d月%d日", y, i, ++j);//相当于i月1日后j天，是i月j+1号
    int w=N%7;
    switch(w)
        {
            case 0:cout<<"星期四"<<endl;break;
            case 1:cout<<"星期五"<<endl;break;
            case 2:cout<<"星期六"<<endl;break;
            case 3:cout<<"星期日"<<endl;break;
            case 4:cout<<"星期一"<<endl;break;
            case 5:cout<<"星期二"<<endl;break;
            case 6:cout<<"星期三"<<endl;break;
        }
    
    }
}

int run4_YorN(int y)
{
    int x;
    if (y % 100 != 0 && y % 4 == 0 || y % 100 == 0 && y % 400 == 0)
        x = 1;
    else
        x = 0;
    return x;
}