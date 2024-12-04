#include <iostream>
using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
        int sum=0;
        for(int i=1;i<num;i++)
        {
            if(num%i==0)
            {
                sum+=i;
            }
            else continue;
        }
        if(sum==num) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}