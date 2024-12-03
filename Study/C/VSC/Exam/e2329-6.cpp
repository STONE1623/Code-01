#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int sum=0;
        for(int i=1;i<str.length();i++)
        {
            if(str[i]=='*')
            {
                if(str[i-2]=='+'||i==1)
                {
                    sum+=(str[i-1]-48)*(str[i+1]-48);
                    str[i-1]=48;str[i+1]=48;str[i]='+';
                }
                if(str[i-2]=='-')
                {
                    sum-=(str[i-1]-48)*(str[i+1]-48);
                    str[i-1]=48,str[i+1]=48;str[i]='+';
                }
            }
        }
        for(int i=0;i<str.length()-1;i++)
        {
            if(str[i]=='+')
            {
                sum+=(str[i-1]-48)+(str[i+1]-48);
                str[i-1]=48;str[i+1]=48;
            }
            else
            {
                sum+=(str[i-1]-48)-(str[i+1]-48);
                str[i-1]=48;str[i+1]=48;
            }
        }
        cout<<sum<<endl;
    }
}