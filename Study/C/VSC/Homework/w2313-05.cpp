#include <iostream>
using namespace std;

void c(double a[],double b[],int O,int M)
{
    /*int n1=sizeof(a[N])/sizeof(a[0]);
    int n2=sizeof(b[M])/sizeof(b[0]);*/
    int n=O+M;
    int n1=O;
    int n2=M;
    const int N=n;
    double c[N];
    for(int i=0;i<n1;i++)
    {
        c[i]=a[i];
    }
    for(int i=0;i<n2;i++)
    {
        c[n1+1]=b[i];
    }
    for(int i=0;i<N-1;i++)
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
                    min2=c[p];
                    s=p;
                }
            }
        }
        if(s!=i)
        {
            int t=c[s];
            c[s]=c[i];
            c[i]=t;
        }
    }
    for(int o=0;o<N;o++)
    {
        cout<<c[o]<<" ";
    }
}

int main()
{
    void c(double,double,int,int);
    int n=0;int m=0;
    while(cin>>n>>m)
    {
        const int N=n;const int M=m;
        double a[N];double b[M];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<N;i++)
        {
            cin>>b[i];
        }
        c(a[N],b[M],N,M);

    }

}