#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num=0;int x=0;
    while(cin>>num)
    {
        int flag=0;
        int *arr=new int[num];
        for(int i=0;i<num;i++) cin>>arr[i];
        cin>>x;
        for(int i=0;i<num;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                if(arr[i]+arr[j]==x)
                {
                    cout<<"TRUE"<<endl;
                    flag=1;
                    break;
                }
                
            }
            if(flag==1) break;
        }
        if(flag==0) cout<<"FALSE"<<endl;
        delete[] arr;
        arr=nullptr;
    }
}