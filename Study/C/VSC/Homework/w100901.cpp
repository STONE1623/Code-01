#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a,b,c,e;
    while(cin>>a>>b>>c)
    {
        if(a<=b)
        {
            if(b<=c) cout<<a<<" "<<b<<" "<<c<<endl;
            else if(c<a) cout<<c<<" "<<a<<" "<<b<<endl;
            else cout<<a<<" "<<c<<" "<<b<<endl;
        }
        else 
        if(b>=c) cout<<c<<" "<<b<<" "<<a<<endl;
        else if(c>=a) cout<<b<<" "<<a<<" "<<c<<endl;
        else cout<<b<<" "<<c<<" "<<a<<endl;
    }
    return 1;
}