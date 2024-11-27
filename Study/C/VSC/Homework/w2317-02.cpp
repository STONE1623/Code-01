#include <iostream>
#include <cmath>
using namespace std;

struct score
{
    int num;
    float sc;
};
;
int main()
{
    int n=0;
    while(cin>>n)
    {
        const int N=n;
        score list[2*n];
        for(int i=0;i<2*n;i++)
        {
            for(int j=0;j<2*n;j++)
            {
                if(list[i].num==list[j].num)
                {
                    cin>>list[i].num>>list[i].sc;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            list[i].sc>list[i+n].sc?:list[i].sc=list[i+n].sc;
        }
        int t1=list[0].sc,t2=list[0].sc,t3=list[0].sc;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(list[j].sc>list[i].sc)
                {
                    float t=list[j].sc;
                    list[j].sc=list[i].sc;
                    list[i].sc=t;
                    int u=list[j].num;
                    list[j].num=list[i].num;
                    list[i].num=u;
                }
            }
        }
        cout<<list[0].num<<" "<<list[0].sc<<endl<<list[1].num<<" "<<list[1].sc<<endl<<list[2].num<<" "<<list[2].sc<<endl;
    }
}