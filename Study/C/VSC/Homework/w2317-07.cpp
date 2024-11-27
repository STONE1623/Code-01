#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int flag=0;
        for(int a=0,b=0;a<str.length();)
        {
        if(str.find("{",a)>=0&&str.find("{",0)<=str.length())
        {
            a=str.find("{",0);
            b=str.find("}",a);
            if(b>a&&b<=str.length()) flag=0;
            else{flag=1;break;}
        }         cout<<flag<<" "<<a<<endl;
        a+=1;
        }

        for(int a=0,b=0;a<str.length();)
        {
        if(str.find("(",a)>=0&&str.find("(",0)<=str.length())
        {
            a=str.find("(",0);
            b=str.find(")",a);
            if(b>a&&b<=str.length()) flag=0;
            else{flag=1;break;}
        }         cout<<flag<<" "<<a<<endl;
        a+=1;
        }
        cout<<flag<<endl;
    }
}