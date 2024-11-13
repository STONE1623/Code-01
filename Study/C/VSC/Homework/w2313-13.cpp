#include <iostream>
using namespace std;

int main()
{
    char name[5][20] = { "li ming", "zhang qing", "liu xiao ping", "wang yin", "lu pei" };
    long num[5] = { 20030001, 20030002, 20030005, 20030007, 20030010 };
    int n=0;
    while(cin>>n)
    {
        int flag=0,i=0;
        
        for(;i<5;i++)
        {
            if(n==num[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<name[i]<<endl;
        else cout<<"未找到该学生的信息。"<<endl;
    }
}