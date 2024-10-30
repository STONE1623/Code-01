#include <iostream>
using namespace std;

int main()
{
    int m;
    while(cin>>m)
    {
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            if(m%i==0) 
            {
                sum+=i;
                m=m/i;
                
            }
            
        }
        cout<<sum;
    }
}