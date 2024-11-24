#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
    int n=0;
    while(cin>>n)
    {
        
        const int N=n;
        string a[N];
        char *b[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        string* min=min_element(a,a+n);
        cout<<*min<<endl;
        /*int x=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<a[i].length();j++)
            {
                b[x]+=a[i][j];
            }

            b[x]+='\0';
        }
        //if(strcmp(a[1],a[2])==1) cout<<1;;
        /*for(int j=0;j<n;j++)
        {
            cout<<a[j]<<endl;
        }*//*/*
        for(int j=0;j<x;j++)
        {
            cout<<b[j]<<endl;
        }
        int q=0,w=0,e=0;*/

        /*for(int i=0;i<x;i++)
        {
            for(int z=i+1;z<n;z++)
            {
                if(strcmp(b[z],b[i])<0)
                {
                    i=z;
                    q=i;
                }
            }
        }*/
        //cout<<b[1];
        //for()
        // string a;string b=0;
        // for(int i=0;i<n;i++)
        // {
        //     getline(cin,a);
        //     /*if(b<a[i])
        //     {
        //         b=a[i];
        //     }*/
        // }
        // //cout<<b<<endl;
    }
}