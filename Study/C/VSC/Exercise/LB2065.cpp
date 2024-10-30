#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    int num,n1,s1,n,s,m;
    num = 0;
    cin>>num;
    vector <int> sep(num);
    cin>>n1>>s1;
    int i=0;
    while(cin>>n>>s)
    {
        if(1.0*s1/n1-1.0*s/n>0.05) sep[i]=0;
        else if(1.0*s/n-1.0*s1/n1>0.05) sep[i]=1;
        else sep[i]=2;
        i++;
        if(i>=num-1) break;
    }
    for(int j=0;j<=num-2;j++)
    {
        if (sep[j]==0) cout<<"worse"<<endl;
        else if(sep[j]==1) cout<<"better"<<endl;
        else cout<<"same"<<endl;
    }

}

