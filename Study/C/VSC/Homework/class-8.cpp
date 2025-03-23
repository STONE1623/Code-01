#include <string>
#include <iostream>
using namespace std;

class Student {

public:
    static int Ch;
    static int En;
    static int Math;
    int num;
    string name;
    char sex;
    int eng;
    int chi;
    int mat;
    int sum;
    static double getAvgEn()
    {
        return Student ::En*1.0/5;
    }
    static int getAvgCh()
    {
        return 1.0*Student ::Ch/5;
    }
    static int getAvgMath()
    {
        return 1.0*Student ::Math/5;
    }
    bool operator>(Student &e) {
        if (sum > e.sum) 
            return 1;
        else 
            return 0;
    }
};
int Student::Ch=0;int Student::En=0;int Student::Math=0;

class ScienceStudent:public Student
{
public:
    int phy;
    int che;
    int bio;
    static int get_average()
    {
        return 1.0*ScienceStudent ::Sum/5;
    }
    friend istream & operator>>(istream & cin,ScienceStudent & e);
protected:
    static int Sum;
};
int ScienceStudent::Sum=0;
class LiberalArtsStudent:public Student
{
public:
    int his;
    int geo;
    int pol;
    static int get_average()
    {
        return 1.0*LiberalArtsStudent ::Sum/5;
    }
    friend istream & operator>>(istream & cin,LiberalArtsStudent & e);
protected:
    static int Sum;
};
int LiberalArtsStudent::Sum=0;
ostream & operator<<(ostream & cout,ScienceStudent & e)
{
    cout<<e.num<<"\t"<<e.name<<"\t"<<e.sex<<"\t"<<e.eng<<"\t"<<e.chi<<"\t"<<e.mat<<"\t"<<e.phy<<"\t"<<e.che<<"\t"<<e.bio<<"\t"<<e.sum<<endl;
    return cout;
}
ostream & operator<<(ostream & cout,LiberalArtsStudent & e)
{
    cout<<e.num<<"\t"<<e.name<<"\t"<<e.sex<<"\t"<<e.eng<<"\t"<<e.chi<<"\t"<<e.mat<<"\t"<<e.his<<"\t"<<e.geo<<"\t"<<e.pol<<"\t"<<e.sum<<endl;
    return cout;
}
istream & operator>>(istream & cin,ScienceStudent & e)
{
    cin>>e.num>>e.name>>e.sex>>e.eng>>e.chi>>e.mat>>e.phy>>e.che>>e.bio;
    e.sum=e.eng+e.chi+e.mat+e.phy+e.che+e.bio;
    Student::Ch+=e.chi;Student::En+=e.eng;Student::Math+=e.mat;
    ScienceStudent::Sum+=e.sum;
    return cin;
}
istream & operator>>(istream & cin,LiberalArtsStudent & e)
{
    cin>>e.num>>e.name>>e.sex>>e.eng>>e.chi>>e.mat>>e.his>>e.geo>>e.pol;
    e.sum=e.eng+e.chi+e.mat+e.his+e.geo+e.pol;
    Student::Ch+=e.chi;Student::En+=e.eng;Student::Math+=e.mat;
    LiberalArtsStudent::Sum+=e.sum;
    return cin;
}
int main() {
    ScienceStudent stu_ss[5];
    LiberalArtsStudent stu_las[5];
    int i;

    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物" << endl;
    for (i = 0; i < 5; i++) 
        cin >> stu_ss[i];

    cout << "\n理科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物\t总分\n";
    for (i = 0; i < 5; i++) 
        cout << stu_ss[i] << endl;

    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治" << endl;
    for (i = 0; i < 5; i++) 
        cin >> stu_las[i];

    cout << "\n文科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治\t总分\n";
    for (i = 0; i < 5; i++) 
        cout << stu_las[i] << endl;

    cout << "The average of English:" << Student::getAvgEn() 
         << "\tChinese:" << Student::getAvgCh() 
         << "\tMath:" << Student::getAvgMath() << endl;

    ScienceStudent::get_average();
    LiberalArtsStudent::get_average();

    return 0;
}