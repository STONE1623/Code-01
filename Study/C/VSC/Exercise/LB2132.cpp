#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int len=a.length();
    string b;
    int tempnum=1;
    for(int i=0;i<len;i++)
    {
        
        if(a[i+1]==a[i]) tempnum++;
        else
        {
            b.append(to_string(tempnum));
            b.append(1,a[i]);
            tempnum=1;
        }
    }
    cout<<b;
}