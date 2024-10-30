#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n,s;
    while(cin>>n)
    {
        s=0;
        for(int i=1;i<=n;i++)
        {
            s+=i;
        }
        cout<<s<<endl;
    }
}