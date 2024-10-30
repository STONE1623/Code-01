#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int m;
    while(cin>>m)
    {
        int i=0;
        do
        {
            cout<<"* ";
            i++;
        } while (i<m-1);
        cout<<"*"<<endl;
        
        for(int i=0;i<=m-3;i++)
        {
            cout<<"*";
            for(int n=2*m-3;n>0;n--)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
        int l=0;
        do
        {
            cout<<"* ";
            l++;
        } while (l<m-1);
        cout<<"*"<<endl;
        
    }
}