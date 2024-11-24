#include <iostream>
#include <climits>
using namespace std;

int main()
{
    struct student 
    {
        char name[50];
        int score;
    };
    struct student arr[10]={
        {"李小平", 90},
        {"何文章", 66},
        {"刘大安", 87},
        {"江立新", 93},
        {"罗建国", 72},
        {"陆丰收", 81},
        {"杨勇", 85},
        {"昊一兵", 55},
        {"伍晓笑", 68},
        {"张虹虹", 93}};
    
    int max=arr[0].score;int i=0,n=0;
    int m[10]={0};
    for(;i<10;i++)
    {
        if (arr[i+1].score>=max)
        {
            max=arr[i+1].score;
            m[i+1]=i+1;
        }
    }
    for(int j=0;j<5;j++)
    {
        if(m[j]!=0)
        {
            cout<<arr[j].name<<" "<<arr[j].score<<endl;
        }
    };
    for(int j=5;j<10;j++)
    {
        if(m[j]!=0)
        {
            cout<<arr[j].name<<" "<<arr[j].score<<endl;
        }
    };
}