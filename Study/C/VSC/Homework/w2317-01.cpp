#include <iostream>
using namespace std;

int main()
{
    char num[5];char cnum[5];int a=0,b=0,c=0;
    while(cin>>num)
    {
        //cout<<num<<endl;
        //cout<<a<<" "<<b<<endl;
        int i=0;
        for(i=0;num[i]!='\0';i++) ;cout<<i<<endl;
        for(int j=0;j<i;j++) cnum[j]=num[i-1-j];
        cout<<cnum<<endl;
        cout<<a<<endl;
        int flag=0;
        for(int k=1;k<17;k++)
        {
            for(int l=0;l<i;l++) 
            {
                if(num[l]!=cnum[l]) {flag=1;break;}
                else flag=0;
            }
            if(flag==1)
            {
                for(int l=0;l<i;l++) num[l]+=cnum[l];
            }
            else break;
        }
        cout<<num;
    }
}