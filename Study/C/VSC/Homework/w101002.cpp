#include <iostream>
#include <climits>
using namespace std;

int main()
{
    char a,b;
    while(cin>>a>>b)
    {
        if(a=='s')
        {
            if(b=='s') cout<<"平局"<<endl;
            if(b=='p') cout<<"甲方胜"<<endl;
            if(b=='r') cout<<"乙方胜"<<endl;
        }
        if(a=='r')
        {
            if(b=='s') cout<<"甲方胜"<<endl;
            if(b=='p') cout<<"乙方胜"<<endl;
            if(b=='r') cout<<"平局"<<endl;
        }
        if(a=='p')
        {
            if(b=='s') cout<<"乙方胜"<<endl;
            if(b=='p') cout<<"平局"<<endl;
            if(b=='r') cout<<"甲方胜"<<endl;
        }
    }
    return 0;
}