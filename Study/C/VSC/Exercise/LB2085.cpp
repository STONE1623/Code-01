#include <iostream>
using namespace std;

int panduan(int n)
{
    if(n==1) return 1;
    else{
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0) return 0;
        }
        return 1;
    }
}
int main()
{
    int num;
    cin>>num; 
    int n=2; //第Num小
    for(int i=1;i<=num;i++)
    {
        while(panduan(n)==0)
        {
            n+=1;
        }
        n+=1;
    }
    cout<<n-1<<endl;
}