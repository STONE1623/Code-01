#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char arr[1000000];
    while(cin>>arr)
    {
        int fp=0,fd=0,fn=0;
        for(int i=0;arr[i]!='\0';i++)
        {
            if(arr[i]>=65&&arr[i]<=90) fp+=1;
            if(arr[i]>=97&&arr[i]<=122) fd+=1;
            if(arr[i]>=48&&arr[i]<=57) fn+=1;
        }
        cout<<fp<<" "<<fd<<" "<<fn<<endl;
    }
}