#include <iostream>
using namespace std;

void fun(int *a,int n )
{
    int i=0;
    for(;i<10;i++)
    {
        if(n<a[i])
        {
            break;
        }
    }
    int b[10]={10,12,23,25,48,48,53,58,60,78};
    a[i]=n;
    for(;i<9;i++)
    {
        a[i+1]=b[i];
    }
    

}
int main()
{
    //void fun(int *,int);
    int n=0;
    while(cin>>n)
    {
        int a[] = { 10, 12, 23, 25, 48, 48, 53, 58, 60, 78 };
        fun(a,n);
        for(int j=0;j<9;j++) cout<<a[j]<<" ";
        cout<<a[9]<<endl;
    }

}