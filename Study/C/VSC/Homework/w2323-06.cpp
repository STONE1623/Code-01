#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num=0;
    while(cin>>num)
    {
        for(int i=0;i<num;i++)
        {
            cin.ignore();
            string line;

            getline(cin,line);
            //cout<<line<<endl;
            int anum=0;
            for(int j=0;j<line.length();j++)
            {
                if(line[j]=='0'||line[j]=='1'||line[j]=='2'||line[j]=='3'||line[j]=='4'||line[j]=='5'||line[j]=='6'||line[j]=='7'||line[j]=='8'||line[j]=='9') anum++;
            }
            if(line.find('@')!=string::npos)
            {
                for(int k=1;k<line.find('@')-1;k++)
                {
                    line[k]='*';
                }
                cout<<line<<endl;
            }
            //if(line.find('+')!=string::npos||line.find('-')!=string::npos||line.find('(')!=string::npos||line.find(')')!=string::npos||line.find(' ')!=string::npos&&)
            if(anum!=0)
            {
                string phone;
                cout<<anum<<endl;
                if(anum==10)
                {
                    int k=0;
                    for(;k<=line.length();k++)
                    {
                        //if(line[k]!='('||line[k]!=')'||line[k]!='+'||line[k]!='-'||line[k]!=' ')
                        if(line[k]=='0'||line[k]=='1'||line[k]=='2'||line[k]=='3'||line[k]=='4'||line[k]=='5'||line[k]=='6'||line[k]=='7'||line[k]=='8'||line[k]=='9')
                        {
                            phone+=line[k];
                            cout<<phone<<" "<<k<<endl;
                        }
                        if(phone.length()==3||phone.length()==7)
                        {
                            phone+='-';  
                        }
                    }
                    cout<<phone<<endl;
                    for(k=k-4;k>=0;k--)
                    {
                        if(phone[k]!='-') phone[k]='*';
                    }
                    cout<<phone;
                }
                if(anum>10)
                {
                    int k=0;
                    phone+='+';
                    cout<<phone<<endl;
                    for(;k<=line.length();k++)
                    {
                        if(line[k]=='0'||line[k]=='1'||line[k]=='2'||line[k]=='3'||line[k]=='4'||line[k]=='5'||line[k]=='6'||line[k]=='7'||line[k]=='8'||line[k]=='9')
                        {
                            phone+=line[k];
                        }//+*-***-***-1111
                        if(anum==11&(phone.length()==2||phone.length()==6||phone.length()==10)) phone+='-';
                        if(anum==12&(phone.length()==3||phone.length()==7||phone.length()==11)) phone+='-';
                        cout<<phone<<endl;
                    }
                    cout<<phone<<endl;
                    for(k=0;k<phone.length()-5;k++)
                    {
                        if(phone[k]!='-'&&phone[k]!='+') phone[k]='*';
                    }                        
                    cout<<phone<<endl;

                }

            }
        }
    }
}