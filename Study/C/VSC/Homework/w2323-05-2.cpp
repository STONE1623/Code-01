#include <iostream>
using namespace std;

int main()
{
    int num=0;
    while(cin>>num)
    {
        for(int i=0;i<num;i++)
        {
            int amount = 0;
            cin>>amount;
            const int N=amount;
            //int *number=new int[amount];
            int number[N];
            for(int i=0;i<amount;i++) cin>>number[i];
            //for(int i=0;i<amount-1;i++) cout<<number[i]<<" ";
            //cout<<number[amount-1]<<endl;            
            if(amount==2)
            cout<<number[1]<<" "<<-1<<endl;
            
            if(amount!=2)
            {
                for(int i=0;i<amount;i++)
                {
                    int max=number[i+1];
                    for(int j=i+1;j<amount;j++)
                    {
                        if(number[j]>max) max=number[j];
                    }
                    number[i]=max;
                }
                number[amount-1]=-1;
                for(int i=0;i<amount-1;i++) cout<<number[i]<<" ";
                cout<<number[amount-1]<<endl;
            }
            //delete[]number;
        }
        
    }
}