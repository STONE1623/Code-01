#include <iostream>
using namespace std;

void pack(unsigned char b[],int a[],const int N)
{
    for(int i=0;i<N;i++) b[i]=a[i];
    //return b;
}

void unpack(unsigned char b[],int c[],const int N)
{
    for(int i=0;i<N;i++) c[i]=b[i];
}

int main()
{
    int n=0;
    while(cin>>n)
    {
        const int N=n;
        int inta[N];
        unsigned char charb[N];
        int intc[N];
        for(int i=0;i<N;i++) cin>>inta[i];
        pack(charb,inta,N);
        for(int i=0;i<N-1;i++) cout<<static_cast<int>(charb[i])<<" ";
        //cout<<"\b\b}\n";
        cout<<static_cast<int>(charb[N-1])<<endl;
        unpack(charb,intc,N);
        for(int i=0;i<N-1;i++) cout<<intc[i]<<" ";
        cout<<intc[N-1]<<endl;
        //cout<<"\b\b}\n";
    }
}