#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

void trans(int n)
{
    int a[9];
    int i;
    while(n>0)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }
    for(int j=i-1;j>=0;j--)
        cout<<a[j];
}
int main()
{
    long d=1;

    long b,o,h;
    
    
    cout<<"decimal\tbinary\t\toctal\thexadecimal"<<endl;
    for(d=1;d<=256;d++)
    {
        int d1=d;
        string a;
        //while (d1 != 0) 
        //{
       //     a += (d1 % 2 == 0 ? "0" : "1");
       //     d1 /= 2;
       // }
        //bitset<9> bs(d);  //存在问题，输出二进制为自己定义的长度而不是实际长度
        cout<<dec<<d<<"\t";
        trans(d);
        if(d<128)
        cout<<"\t\t"<<oct<<d<<"\t"<<hex<<d<<"\t"<<endl;  
        else 
        cout<<"\t"<<oct<<d<<"\t"<<hex<<d<<"\t"<<endl;

    }
}