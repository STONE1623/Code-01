#include <iostream>

using std::cout;
using std::endl;
using std::string;

void trans(int n)
{
    int a[9];
    int i=0;
    while(n>0)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }
    for(int j=i-1;j>=0;j--)
        cout<<a[j];
}

int main()
{
    trans(12);
}