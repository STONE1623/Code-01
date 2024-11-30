#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int num=str.length();
        for(int i=0;i<num;i++)
        {
            cout<<str[i]<<"*";
        }
        cout<<endl;
    }
}