#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        const int N=n;
        int a[N];
        for(int i=0;i<N;i++) cin>>a[i];
        for(int k=0;k<N;k++)
        {
            int s=k;int t=0;
            for(int b=k+1;b<n;b++)
            {
                if(a[b]<a[k]) s=b;
            }
            if(s!=k)
            {
                t=a[s];
                a[s]=a[k];
                a[k]=t;

            }
            for(int y=0;y<N;y++)
            {
                cout<<a[y]<<" ";
            }
            cout<<endl;
        }
        for(int y=0;y<N;y++)
        {
            cout<<a[y]<<" ";
        }
    }
}