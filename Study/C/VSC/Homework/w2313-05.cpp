#include <iostream>
using namespace std;

void c(double a[],double b[],int I,int M)
{
    /*int n1=sizeof(a[N])/sizeof(a[0]);
    int n2=sizeof(b[M])/sizeof(b[0]);*/
    int n=I+M;
    int n1=I;
    int n2=M;
    const int N=n;
    double c[N];
    for(int i=0;i<n1;i++)
    {
        c[i]=a[i];
    }
    for(int i=0;i<n2;i++)
    {
        c[n1+i]=b[i];
    }
    /*for(int i=0;i<N;i++) cout<<c[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<N;i++)
    {
        int min1=c[i];int min2=c[i];int s=i;//min1:当前较小值；min2：上一个较小值
        for(int p=i+1;p<N;p++)
        {
            if(c[p]<c[i])
            {
                min1=c[p];
                if(min2<c[p])
                {
                    min1=min2;
                }
                else
                {
                    s=p;
                }
                min2=min1;
            }
        }
        if(s!=i)
        {
            int t=c[s];
            c[s]=c[i];
            c[i]=t;
        }
    }
    for(int o=0;o<N-1;o++)
    {
        cout<<c[o]<<" ";
    }
    cout<<c[N-1]<<endl;
}

int main()
{
    void c(double [],double [],int,int);
    int n=0;int m=0;
    while(cin>>n>>m)
    {
        const int N=n;const int M=m;
        double a[N];double b[M];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<M;i++)
        {
            cin>>b[i];
        }
        c(a,b,N,M);
    }
}