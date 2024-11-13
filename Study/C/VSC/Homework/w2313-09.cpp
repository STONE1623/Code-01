#include <iostream>
using namespace std;

void fun(int *a,int const N)
{
    //int n=sizeof(a)/sizeof(a[0]);
    int i=0;int s=0;
    int min1=0,min2=0;
    min1=a[i],min2=a[i];
    for(int j=i+1;j<N;j++)
    {
        if(a[j]<a[i])
        {
            min1=a[j];
            if(min2<min1)
            {
                min1=min2;
            }
            else if(min2>min1)
            {
                s=j;
            }
            min2=min1;
        }
    }
    cout<<min2<<" "<<s<<endl;
}
int main()
{
    void fun(int *,int const);
    int n=0;
    while(cin>>n)
    {
        const int N=n;
        int a[N];
        for(int i=0;i<N;i++) cin>>a[i];
        fun(a,N);
    }
}