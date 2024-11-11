#include <iostream>
#include <climits>
#include <string.h>
using namespace std;

int main()
{
    string a;int num = 0;
    while(cin>>a)
    {
        int x=0;
        num=a.length();
        const int N=num;
        char b[N];
        strcpy(b,a.c_str());
        if(N%2==0) 
        {
            for(int q=0;q<=N/2;q++)
            {
                if(b[q]!=b[N-1-q])
                {
                    x=1;
                    break;
                } 
            }
        }
        else
        {
            for(int q=0;q<(N-1)/2;q++)
            {
                if(b[q]!=b[N-1-q])
                {
                    x=1;
                    break;
                }
            }
        }
        //cout<<a<<endl;
        if(x==1) cout<<"不是回文数"<<endl;
        else cout<<"是回文数"<<endl;
        //for(int i=0;i<N;i++) cout<<b[i]<<" ";
    }
}