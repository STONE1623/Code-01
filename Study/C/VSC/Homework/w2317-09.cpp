#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num=0;
    while(cin>>num)
    {
        int *arr=new int[num];
        for(int i=0;i<num;i++) cin>>arr[i];
        int max=arr[0],min=arr[1],m=m=abs(arr[0]-arr[1]);
        for(int i=0;i<num;i++)
        {
            if(arr[i]>max) max=arr[i];
            if(arr[i]<min) min=arr[i];
        }
        
        for(int i=0;i<num;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                if(abs(arr[i]-arr[j])<m) m=abs(arr[i]-arr[j]);
            }
        }
        cout<<m<<" "<<max-min<<endl;
    }
}