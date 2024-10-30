#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    int i;
    while(cin>>n)
    {
        if(n==1) cout<<"0"<<endl;
        else
        {
        for(i=0;n!=1;i++)
        {
            if(n%2==0)
            {
                n=n*0.5;
                //i++;
            }
            else
            {
                n=(3*n+1)*0.5;
                //i++;
            }  
        }
        cout<<i<<endl;
        }
    }
}