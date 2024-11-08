#include <iostream>
#include <climits>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,f;
    char c;
    cin>>a>>b>>c>>f;
    if(f==0)
    {
        for(int i=1;i<=b;i++)
        {
            cout<<c;
        }
        cout<<endl;
        for(int p=1;p<=a-2;p++)
        {
            cout<<c;
            for(int i=1;i<=b-2;i++)
            {
                cout<<" ";
            }
            cout<<c<<endl;
        }
        for(int p=1;p<=b;p++)
        {
            cout<<c;
        }
    }
    else
    {
        for(int i=1;i<=a;i++)
        {
            for(int p=1;p<=b;p++)
            {
                cout<<c;
            }
            cout<<endl;
        }
    }
}