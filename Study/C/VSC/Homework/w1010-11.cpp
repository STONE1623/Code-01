#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a[6],m;
    while(cin>>m)
    {
        int n1,a1,a2,a3,a4,a5,a6;
        if(m<100000)
        {
            cout<<"输入错误，退出程序。"<<endl;
            continue;
        }
        else
        {
            a[0]=m/100000;a[1]=m/10000%10;a[2]=m/1000%10;a[3]=m/100%10;a[4]=m/10%10;a[5]=m%10;
            for(int i=0;i<6;i++)
            {
                a[i]=(a[i]+7)%10;
            }
            cout<<"加密：";
            for(int j=5;j>=0;j--)
            {
                cout<<a[j];
            }
            cout<<endl<<"解密：";
            a[0]=m/100000;a[1]=m/10000%10;a[2]=m/1000%10;a[3]=m/100%10;a[4]=m/10%10;a[5]=m%10;
            for(int k=0;k<6;k++)
            {
                cout<<a[k];
            }
            cout<<endl;
            
            
        }
    }
    return 0;
}