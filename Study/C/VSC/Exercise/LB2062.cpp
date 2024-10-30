#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a,n,sum;
    cin>>a>>n;
    sum=1;
    for(int i=0;i<n;i++)
    {
        sum*=a;
    }
    cout<<sum;
}