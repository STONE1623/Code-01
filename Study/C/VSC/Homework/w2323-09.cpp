#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;string str2;
    while(cin>>str1>>str2)
    {
        int len1=str1.length();
        int len2=str2.length();
        int max=len1>len2?len1:len2;
        string same;
        for(int i=0;i<max;i++)
        {
            if(str1[i]==str2[i])
            {
                same+=str1[i];
            }
            else break;
        }
        if(same.length()==0) cout<<"-1"<<endl;
        else cout<<same<<endl;
    }
}