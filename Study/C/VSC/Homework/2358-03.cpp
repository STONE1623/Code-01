/*定义一个student 类，在该类定义中包括：一个数据成员（分数score）及两个静态数据成员（总分toal和学生人数count)；
成员函数 scoretotalcount 用于设置分数、求总分和累计学生人数；静态成员函数 sum用于返回总分；静态成员函数average 用于求平均值。
在main 函数中，输入某班学生的成绩，并调用上述函数求全班学生的总分和平均分。
输入
一个班的学生总人数
每个学生的分数
输出
总分
平均分*/
#include <iostream>
using namespace std;

class Student
{
public:
    int score;
    static int total;
    static int count;
    void scoretotalcount(int a)
    {
        score=a;
        count+=1;
        total+=score;
    }
    static int sum()
    {
        return total;
    }
    static float average()
    {
        return 1.0*Student::total/count;
    }
};
int Student::total=0;int Student::count=0;
int main()
{
    int count;
    while(cin>>count)
    {
        for(int i=0;i<count;i++)
        {
            Student a;
            int score;cin>>score;
            a.scoretotalcount(score);
        }
        cout<<Student::sum()<<endl<<Student::average()<<endl;
        Student::total=0;Student::count=0;
    }
}