#include <iostream>
using namespace std;

int main()
{
    int a,x,n1,n2;
    x=500;
    n1=0;n2=1000;
    //cout<<"500"<<endl;
    for(int i=1;;i++)
    {
        cout<<(n2+n1)/2<<endl;  //n2>n1
        cin>>a;
        if(a==0)
        {
            cout<<"猜了"<<i<<"次"<<endl;
            break;
        }
        if(a==-1)
        {
        
            n1=(n2+n1)/2;
        }
        else
        {
            
            n2=(n2+n1)/2;
        }
    }
}