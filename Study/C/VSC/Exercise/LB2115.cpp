#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    getline(cin,a);cout<<a<<endl; 
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==90) a[i]=65;
        else if(a[i]==122) a[i]=97;
        else if(a[i]>90&&a[i]<97||a[i]>122||a[i]<65) continue;
        else a[i]=a[i]-1;
    }
    cout<<a<<endl;
}