#include <iostream>
#include <climits>
#include <cmath>
using namespace std;


void p(int w,int n)
{
    if(w>=1) 
    {
        for(int i=1;i<=(n+1)-w;i++)
        {
            cout<<(n+1)-w<<" ";
        }
        cout<<endl;
        p(w-1,n);
    }

}
int main()
{
    void p(int,int);
    p(5,5);
}