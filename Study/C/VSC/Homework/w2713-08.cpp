#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        int num=0;double sum=0;
        double *p=new double[n];
        for(int i=0;i<n;i++) 
        {
            cin>>p[i];

        }
        for(int i=0;i<n;i++)
        {
            
            if(p[i]>5000&&p[i]<=8000) sum+=0.03*(p[i]-5000);
             if(p[i]>8000&&p[i]<=17000) sum+=0.1*(p[i]-8000)+90;
             if(p[i]>17000&&p[i]<=30000) sum+=0.2*(p[i]-17000)+90+900;
             if(p[i]>30000&&p[i]<=40000) sum+=0.25*(p[i]-30000)+90+900+2600;
             if(p[i]>40000&&p[i]<=60000) sum+=0.30*(p[i]-40000)+90+900+2600+2500;
             if(p[i]>60000&&p[i]<=85000) sum+=0.35*(p[i]-60000)+90+900+2600+2500+6000;
             if(p[i]>85000) sum+=0.45*(p[i]-85000)+90+900+2600+2500+6000+8750;
             if(p[i]<=5000) num+=1;
        }
        cout<<sum<<" "<<n-num<<endl;
    }
}