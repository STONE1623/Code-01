#include <iostream>
using namespace std;

int main()
{
    char *w[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
    string *W;
    /*for(int i=0;i<7;i++)
    {
        W[i]=&w[i];
    }*/
    int a=0;
    while(cin>>a)
    {
        switch(a)
        {
            case 1:cout<<w[0]<<endl;break;
            case 2:cout<<w[1]<<endl;break;
            case 3:cout<<w[2]<<endl;break;
            case 4:cout<<w[3]<<endl;break;
            case 5:cout<<w[4]<<endl;break;
            case 6:cout<<w[5]<<endl;break;
            case 7:cout<<w[6]<<endl;break;
        }
    }
}
