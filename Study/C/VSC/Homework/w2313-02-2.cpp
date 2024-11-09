#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a[]={11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    while(1)
    {
        int c[10];
        int b[10];
        int h=0;
        for(int i=0;i<10;i++)
        {
            cin>>b[i];
            for(int q=0;q<21;q++)
            {
                if(b[i]==a[q])
                {
                    c[h]=b[i];
                    h++;
                }
            }
        }
        int y=0;
        if(h==1)cout<<c[0]<<endl;
        else 
        {
            for(;y<=h-2;y++) cout<<c[y]<<" ";
            cout<<c[h-1]<<endl;
        }    
    }
}