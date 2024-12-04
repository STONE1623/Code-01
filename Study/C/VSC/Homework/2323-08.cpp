#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int panduan(int n)
{
    int flag=0;
    for(int i=2;i<n/2;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int main()
{
    double n=0,m=0;
    while(cin>>n>>m)
    {
        string str;
        double i=1;int num=0;
        while(pow(2,i)-1<n)
        {
            if(pow(2,i+1)-1>=n) break;
            i++;
        }
        double j=i+1;
        while(pow(2,j)-1<=m)
        {
            if(panduan(pow(2,j)-1)==0) num+=1;
            j++;
        }
        int flag2=0;
        int *arr=new int[num];
        j=i+1;int k=0;int num2=0;
        while(pow(2,j)-1<=m)
        {
            if(panduan(pow(2,j)-1)==0)
            {
                arr[k]=(pow(2,j)-1);
                flag2=1;
                num2+=1;
                k++;
            }
            j++;
        }
        //cout<<num2<<endl;
        for(int p=0;p<num2-1;p++)
        {
            cout<<arr[p]<<" ";
        }
        if(num2!=0)cout<<arr[num2-1]<<endl;
        /*for(i+=1;pow(2,i)-1<m;i++)
        {
            if(pow(2,i+1)-1<m&&panduan(pow(2,i)-1)==0)
            {cout<<pow(2,i)-1<<" ";flag2=1;}
            if(pow(2,i+1)-1==m&&panduan(pow(2,i)-1)==0&&panduan(pow(2,i+1)-1)==0)   
            {cout<<pow(2,i)-1<<" "<<pow(2,i+1)-1<<endl;flag2=1;}
            if(pow(2,i+1)-1>m&&panduan(pow(2,i)-1)==0) {cout<<pow(2,i)-1<<endl;flag2=1;}
        }*/
        if(flag2==0) cout<<"-1"<<endl;
    }
}