#include<iostream> 
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int i=2;
    for(;i<1000000;i++)
    {
        if(a%i==b%i&&b%i==c%i) break;
    }
    cout<<i<<endl;
}