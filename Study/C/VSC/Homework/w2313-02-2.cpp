#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int a[]={11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int b[10];
    while(cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5]>>b[6]>>b[7]>>b[8]>>b[9])
    {
        int c[10];
        int h=0;
        for(int i=0;i<10;i++)
        {
            if(b[i]==11||b[i]==13||b[i]==17||b[i]==19||b[i]==23||b[i]==29||b[i]==31||b[i]==37||b[i]==41||b[i]==43||b[i]==47||b[i]==53||b[i]==59||b[i]==61||b[i]==67||b[i]==71||b[i]==73||b[i]==79||b[i]==83||b[i]==89||b[i]==97)
            {
                c[h]=b[i];
                h++;
            }

        }
        int y=0;
        if(h==1)cout<<c[0]<<endl;
        else 
        {
            for(;y<=h-2;y++) cout<<c[y]<<" ";
            cout<<c[h-1]<<endl;
        }    
    }
}