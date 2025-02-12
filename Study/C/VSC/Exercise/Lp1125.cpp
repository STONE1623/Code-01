#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int arr[26]={0};
    while(cin>>str)
    {
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==i-61) str[i]++;
        }
        for(int i=0;i<26;i++)
        {
            
        }
    }
}