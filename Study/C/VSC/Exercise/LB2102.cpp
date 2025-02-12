#include <iostream>
using namespace std;

int main()
{
    int arr[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    int flag2=0;
    for(int i=0;i<5;i++)
    {
        int max=arr[i][0];int maxnum=0;
        for(int j=0;j<5;j++)
        {
            if(arr[i][j]>max){ max=arr[i][j];maxnum=j;}
        }
        int flag=0;
        for(int t=0;t<5;t++)
        {
            if(arr[t][maxnum]<max&&t!=i){flag=1;break;};
        }
        if(flag==1) continue;
        else {cout<<i+1<<" "<<maxnum+1<<" "<<max<<endl;flag2=1;break;}
    }
    if(flag2==0) cout<<"not found"<<endl;
}