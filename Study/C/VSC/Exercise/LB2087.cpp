#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;int m;int num=0;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==m) num+=1;
    }
    cout<<num<<endl;
}