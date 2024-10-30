#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int m;
    while(cin>>m)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<"*";
        }
        cout<<endl;
        if(m-1>=3) 
        {
            for(int o=m-1;o>=3;o--) 
            {
                cout<<"*";
                for(int p=o-3;p>=0;p--)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
            }
            cout<<"**"<<endl<<"*"<<endl<<endl;
        }
        else if(m==2) cout<<"*"<<endl<<endl;
        else cout<<"**"<<endl<<"*"<<endl<<endl;
    }
    return 0;
}