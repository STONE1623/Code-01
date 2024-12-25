#include <iostream>
using namespace std;

struct S
{
    double x;
    double y;

};
int main()
{
    S s1[3]={{1,2},{2,3},{3,4}};S *p=s1;
    
    cout<<s1[0].x<<" "<<(*p).y<<endl;
}