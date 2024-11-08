#include <iostream>
#include <climits>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int l,r,i,sum;
    sum=0;
    string s;
    cin>>l>>r;
    for(i=l;i<=r;i++)
    {
        s=to_string(i);
        sum+=count(s.begin(),s.end(),'2');
    }
    cout<<sum;
}