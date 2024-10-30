#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int m=0;int n=0;int sum,k;
    cin>>m>>n;
    if(m%2==0) m+=1;
    if(n%2==0) n-=1;
    k=(n-m)/2+1;
    sum=(n+m)*k/2;
    cout<<sum;
}