#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num=0;int arrn[5];
    while(cin>>num)
    {
        int amount=0;int flag=0;int cnum=0;
        for(int i=0,cnum=num;cnum!=0;amount++) 
        {
            if(cnum%10!=0)
            {
                cnum/=10;
            }
        }
        cnum=num;
        for(int i=0;i<amount;i++)
        {
            arrn[i]=cnum%10;
            cnum/=10;
        }
        //for(int i=0;i<amount;i++) cout<<arrn[i];
        /*
        for(int i=0;i<amount;i++) 
        {
            if(arrn[i]!=arrn[amount-1-i])
            {
                flag=1;
                break;
            }
            
        }*/
        for(int j=0;j<17;j++) 
        {
            for(int i=0;i<amount;i++) //jiance
            {
                if(arrn[i]!=arrn[amount-1-i])
                {
                    flag=1;
                    break;
                }
                else flag=0;
            }
            if(flag==0) break;
            else
            {
                for(float i=0;i<amount;i++)
                {
                    int q=i;
                    num+=arrn[amount-1-q]*pow(10,i);
                    q+=1;
                }
                amount=0;
                for(int i=0,cnum=num;cnum!=0;amount++) 
                {
                    if(cnum%10!=0)
                    {
                        cnum/=10;
                    }
                }
                cout<<num<<endl<<amount<<endl;
                for(int i=0,cnum=num;i<amount;i++)
                {
                    arrn[i]=cnum%10;
                    cnum/=10;
                }
            }
            //cout<<-1<<endl;
        }
        cout<<num<<endl;
    }
}