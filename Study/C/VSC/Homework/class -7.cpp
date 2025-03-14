#include<string>
#include<iostream>
using namespace std;


class Student
{
public:
    int num;
    string name;
    char sex;
    int eng;
    int chi;
    int mat;
    int sum;
    bool operator>(Student &e)
    {
        if(sum>e.sum) return 1;
        else return 0;
    }
    
};
void  SelectSort(Student *st, int n)  //选择排序
{
    int i,j,t;
    Student  temp;
    for(i=0;i<n-1;i++)
    {
        t=i;
        for (j=i+1;j<n;j++)
        if (st[j]>st[t])  //隐式调用类型转换函数
        t=j;   
        if(t!=i)
        {
            temp=st[i];
            st[i]=st[t];
            st[t]=temp;
        }
    }
    return;
}

istream & operator>>(istream & cin,Student & e)
{
    cin>>e.num>>e.name>>e.sex>>e.eng>>e.chi>>e.mat;
    e.sum=e.eng+e.chi+e.mat;
    return cin;
}
ostream & operator<<(ostream & cout,Student & e)
{
    cout<<e.num<<"\t"<<e.name<<"\t"<<e.sex<<"\t"<<e.eng<<"\t"<<e.chi<<"\t"<<e.mat<<"\t"<<e.sum<<endl;
    return cout;
}
int main()
{
    Student stu[5];
    int i;
    cout<<"请按以下顺序输入学生信息：\n学号\t姓名\t性别\t英语\t语文\t数学"<<endl;
    for(i=0;i<5;i++)
    cin>>stu[i];   // 调用重载的提取运算符
    cout<<"\n按总分降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t总分\n";
    SelectSort(stu,5);
    for(i=0;i<5;i++)
    cout<<stu[i]<<endl;   //调用重载的插入运算符
    return 0;
}