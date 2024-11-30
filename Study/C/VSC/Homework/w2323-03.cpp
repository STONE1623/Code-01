#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num=0;
    while(cin>>num)
    {
        string *arr=new string [num+2];
        string *brr=new string [num];
        for(int i=0;i<num;i++) cin>>arr[i];
        for(int i=0;i<num;i+=1)
        {
            arr[num-i]=arr[0];
            brr[i]=arr[1];
            for(int i=0;i<num;i++)
            {
                arr[i]=arr[i+2];
            }
            /*for(int i=0;i<num+2;i++)
            cout<<arr[i]<<" ";cout<<endl;*/
        }
        for(int i=0;i<num-1;i++)
        cout<<brr[i]<<" ";cout<<brr[num-1]<<endl;
    }

}