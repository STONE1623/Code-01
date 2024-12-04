#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int numarr=0;
    int numele=0;
    while(cin>>numarr)
    {
        for(int i=0;i<numarr;i++){
        cin>>numele;
        int *arr=new int[numele];int sum=0;
        double j=0;
        for(int i=0;i<numele;i++,j++)
        {
            cin>>arr[i];
        }
        j=numele-1;
        for(int i=0;i<numele;i++,j--)
        {
            sum+=arr[i]*pow(2,j);
        }
        cout<<sum<<endl;}
    }
}