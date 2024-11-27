#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a=0,b=0,c=0;
    int price=0,na=0,nb=0,nc=0;
    cin>>a>>b>>c;
    while(cin>>price>>na>>nb>>nc)
    {
        //int price=0,na=0,nb=0,nc=0;
        
        int pa=0,pb=0,pc=0;
        a+=na;b+=nb;c+=nc; //更新硬币数
        int sp=na+nb*5+nc*10-price; //应找钱数
        //cout<<sp<<endl;
        if(sp>=10)
        {
            for(;sp>=(pc+1)*10&&pc<=c&&b!=0;pc++);
            sp-=pc*10;
            if(sp>=5)
            {
                for(;sp>=(pb+1)*5&&pb<=b&&b!=0;pb++);
                sp-=pb*5;
                if(sp>0&&sp<=5) for(pa=0;sp>=(pa+1)&&pa<=a;pa++);
            }

            else if(sp>0&&sp<=5) for(pa=0;sp>=(pa+1)&&pa<=a;pa++);
            

        }
        else if(sp>=5&&sp<10)
        {
            for(;sp>=(pb+1)*5&&pb<=b&&b!=0;pb++);
            sp-=pb*5;
            if(sp>0) for(pa=0;sp>=(pa+1)&&pa<=a;pa++);
        }
        else 
        {
            for(pa=0;sp>=(pa+1)&&pa<=a;pa++);
        }
        //cout<<pa<<endl;//pa+=1;//pb+=1;pc+=1;
        cout<<a-pa<<" "<<b-pb<<" "<<c-pc<<endl;
        a=a-pa;b=b-pb;c=c-pc;
    }
}