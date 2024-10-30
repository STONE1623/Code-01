#include <iostream>
#include <climits>
using namespace std;

int F(int a)
{  //?:Sementation fault
   if(a==1||a==2) return 1;
   else
   {
    int sum=F(a-1)+F(a-2);
    return sum;
    }
}
int main()
{
    int a,n,m;
    n=0;
    cin>>n;
    int *b=new int[n];
    int i=0;
    while(cin>>m)
    {
        b[i]=m;
        i++;
        if(i>m) break;
    }
    for(int j=0;j<=n;j++)
    {
        cout<<F(b[j])<<endl;
    }
    delete [ ] b;
}