#include <iostream>
#include <climits>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int a[]={11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int b[10];
    while(cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5]>>b[6]>>b[7]>>b[8]>>b[9])
    {
        /*
        for(int i=0;i<10;i++)
        {
            cin>>b[i];
        }*/
        int c[10];
        int h=0;
        for(int j=0;j<21;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(b[k]==a[j])
                {
                    c[h]=a[j];
                    h++;
                }
            }
        }
        int y=0;
        if(h==1)cout<<c[0]<<endl;
        else 
        {
            for(;y<=h-2;y++)
            {
                cout<<c[y]<<" ";
            }
            cout<<c[h-1]<<endl;
        }
        
            
    }
}