#include <iostream>
#include <string>
using namespace std;
/*
int main()
{
    int num;
    while(cin>>num)
    {
        for(int i=0;i<num;i++) 
        {
            string str;            
            cin>>str;
            for(int i=0;i<str.length();i++) cout<<str[i]<<" ";*/
            /*for(int j=str.length();j>0;j-=2)
            {
                int flag=0;
                for(int h=j+2;h>0;h++)
                {
                    if(str[j]==str[h]) cout<<str[j]<<endl;
                    flag=1;
                    break;
                }
                if(flag==1) break;
            }
        }  */
        //delete str[];          
        //for(int i=0;i<num;i++) cout<<str;
        /*for(int i=0;i<num;i++)
        {

            for(int j=str[i].length();j>0;j-=2)
            {
                int flag=0;
                for(int h=j+2;h>0;h++)
                {
                    if(str[j]==str[h]) cout<<str[j]<<endl;
                    flag=1;
                    break;
                }
                if(flag==1) break;
            }
        }*/
        
    
int main()
{
    int num;
    while(cin>>num)
    {
        for(int i=0;i<num;i++)
        {
            int *arr=new int;
            int j;
            for(j=0;cin.get()!='\n';j++)
            {
                cin>>arr[j];
            }
            int n=j;
            //cout<<j;
            for(j=0;j<n;j++)
            {
                int flag=0;
                for(int i=j+1;i<n;j++)
                {
                    if(arr[j]==arr[i])
                    {
                        cout<<arr[j]<<endl;
                        flag=1;
                        break;
                        arr[j]=NULL;
                    }
                }
                if(flag==1) break;
            }
        }
    }
}

