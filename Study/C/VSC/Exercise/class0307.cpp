#include<iostream>
#include<string>
using namespace std;

class Student
{
    static int sumchi,summat,sumeng,numstu;
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
        numstu++;
        sumchi+=chinese;
        summat+=math;
        sumeng+=english;
    };
    Student(const Student & p)
    {
        name=p.name;
        number=p.number;
        sex=p.sex;
        chinese=p.chinese;
        math=p.math;
        english=p.english;
        numstu++;
        sumchi+=chinese;
        summat+=math;
        sumeng+=english;
    };
    ~Student() {};
    void show()
    {
        cout<<"学号："<<number<<"\t"<<"姓名："<<name<<"\t"<<"性别："<<sex<<"\t"<<"英语："<<english<<"\t"<<"语文："<<chinese<<"\t"<<"数学："<<math<<"\t"<<endl;
    };
    static double avg_eng()
    {
        return 1.0*sumeng/numstu;
    }
    static double avg_chi()
    {
        return 1.0*sumchi/numstu;
    }
    static double avg_math()
    {
        return 1.0*summat/numstu;
    }
};

int Student::sumchi = 0;
int Student::summat = 0; 
int Student::sumeng = 0;
int Student::numstu = 0;

int main()
{
Student std_1(1001,"Li Hua",'F',91,71,81);
Student std_2(1002,"HeXiao",'M',92,72,82);
Student std_3=std_1, std_4;
cout<<"英语的平均分是："<<Student::avg_eng()<<endl
<<"中文的平均分是："<<Student::avg_chi()<<endl
<<"数学的平均分是："<<Student::avg_math()<<endl;
return 0;
}