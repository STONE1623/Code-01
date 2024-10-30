#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int m;
    while(cin>>m)
    {
        for(int h=m-1;h>=1;h--)
        {
            cout<<" ";
        }
        cout<<"*"<<endl;
        for(int l=m-2;l>=1;l--)  //行
        {
            for(int i=l-1;i>=0;i--) //空
            {
                cout<<" ";
            }
            cout<<"*";
            for(int n=m-l-2;n>=1;n--)
            {
                cout<<" ";
            }
            cout<<"*";
            cout<<endl;        
        }
        
        for(int k=m;k>=1;k--)
        {
            cout<<"*";
        }
        cout<<endl<<endl;

    }
}