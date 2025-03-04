#include<cstring>
#include<iostream> 
#include<string>
using namespace std;

class Student
{
private:
    int number=0;
    string name="noname";
    char sex=0;
    int chinese=0;
    int math=0;
    int english=0;
public:
    Student(int n=0,string n2="noname",char s=0,int e=0,int c=0,int m=0)
    {
        number=n;
        name=n2;
        sex=s;
        chinese=c;
        math=m;
        english=e;
    };
    Student(const Student & p)
    {
        name=p.name;
        number=p.number;
        sex=p.sex;
        chinese=p.chinese;
        math=p.math;
        english=p.english;
    };
    ~Student() {};
    void show()
    {
        cout<<"学号："<<number<<"\t"<<"姓名："<<name<<"\t"<<"性别："<<sex<<"\t"<<"英语："<<english<<"\t"<<"语文："<<chinese<<"\t"<<"数学："<<math<<"\t"<<endl;
    };
};

int main()
{
 Student std_1(1001,"Li Hua",'F',91,71,81);
 Student std_2(1002,"HeXiao",'M',92,72,82);
 Student std_3=std_1;
Student std_4;
 std_1.show();
 std_2.show();
 std_3.show();
 std_4.show();
 return 0;
}