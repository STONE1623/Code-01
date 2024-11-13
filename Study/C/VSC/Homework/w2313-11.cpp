#include <iostream>
using namespace std;

char pack(int *p,char b[],int n)
{
    //const int N=n;
    for(int i=0;i<n;i++)
    {
        b[i]=(p[i]>> (i * 8)) & 0xFF;
    }
    return b[N];
}

int *unpack(char *b,int *c,int n)
{
    for(int i=0;i<n;i++)
    {
        c[i]=(int)(b[i] - '0');
    }
    return c;
}
int main()
{
    int n;
    while(cin>>n)
    {
        const int N=n;
        char b[N];
        int p[N];
        int c[N];
        /*
        char *b=new char[n];
        int *p=new int[n];
        int *c=new int[n];
        */
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        for(int i=0;i<n-1;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<p[n-1]<<endl;
        pack(p,b,n);
        b[N]=pack(p,b[N],n);
        for(int i=0;i<n-1;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<b[n-1]<<endl;
        for(int i=0;i<n-1;i++)
        {
            cout<<c[i]<<" ";
        }
        cout<<c[n-1]<<endl;
        delete []p;
        delete []b;
        delete []c;
    }
    
}