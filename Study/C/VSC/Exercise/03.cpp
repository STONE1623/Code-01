#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n,e,m,o;o=0;
    while(cin>>n)
    {
        cout<<endl;
        while(cin>>e)
        {
            if(e>=m) m=e;
            o++;
            if(o==n) break;
        }
    cout<<m<<endl;
    }   
}