#include <iostream>
//#include <string>
//#include <cstring>
#include <string.h>
using namespace std;

int main()
{
    string word1,word2;
    
    while(cin>>word1>>word2)
    {
        int sta1[26]={0},sta2[26]={0};
        int n1=word1.length();
        int n2=word2.length();
        char*w1=new char[n1+1];
        char*w2=new char[n2+1];
        strncpy(w1,word1.data(),n1);
        strncpy(w2,word2.data(),n2);
        for(int i=0;i<26;i++)
        {
            sta1[w1[i]-97]+=1;
            sta2[w2[i]-97]+=1;
        }
        int flag=0;
        for(int i=0;i<26;i++)
        {
            //cout<<sta1[i]<<" "<<sta2[i]<<endl;
            if(sta1[i]!=sta2[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}