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
        return 1.0*Student ::En/10;
    }
    static float getAvgCh()
    {
        return 1.0*Student ::Ch/10;
    }
    static float getAvgMath()
    {
        return 1.0*Student ::Math/10;
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
protected:
    static int Phy;
    static int Che;
    static int Bio;
public:
    int phy;
    int che;
    int bio;
    static void get_average()
    {
        cout << "The average of physics:" << 1.0*ScienceStudent::Phy/5 
        << "\tchemistry:" << 1.0*ScienceStudent::Che/5
        << "\tbiology:" << 1.0*ScienceStudent::Bio/5 << endl;
    }
    friend istream & operator>>(istream & cin,ScienceStudent & e);
};
int ScienceStudent::Phy=0;int ScienceStudent::Che=0;int ScienceStudent::Bio=0;
class LiberalArtsStudent:public Student
{
protected:
    static int His;
    static int Geo;
    static int Pol;
public:
    int his;
    int geo;
    int pol;
    static void get_average()
    {
        cout << "The average of history:" << 1.0*LiberalArtsStudent::His/5 
        << "\tgeography:" << 1.0*LiberalArtsStudent::Geo/5
        << "\tpolitics:" << 1.0*LiberalArtsStudent::Pol/5 << endl;
    }
    friend istream & operator>>(istream & cin,LiberalArtsStudent & e);
};
int LiberalArtsStudent::His=0;int LiberalArtsStudent::Geo=0;int LiberalArtsStudent::Pol=0;
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
    ScienceStudent::Phy+=e.phy;ScienceStudent::Che+=e.che;ScienceStudent::Bio+=e.bio;
    return cin;
}
istream & operator>>(istream & cin,LiberalArtsStudent & e)
{
    cin>>e.num>>e.name>>e.sex>>e.eng>>e.chi>>e.mat>>e.his>>e.geo>>e.pol;
    e.sum=e.eng+e.chi+e.mat+e.his+e.geo+e.pol;
    Student::Ch+=e.chi;Student::En+=e.eng;Student::Math+=e.mat;
    LiberalArtsStudent::His+=e.his;LiberalArtsStudent::Geo+=e.geo;LiberalArtsStudent::Pol+=e.pol;
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