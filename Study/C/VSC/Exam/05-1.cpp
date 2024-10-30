#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,x,v1,v2,t;
	while(cin>>v2>>v1>>x>>t)
    {
	a=x/(v1-v2);
	if(a<=t){
		//cout<<"Yes ";
		printf("%.2lf",a);
        cout<<endl;
    }
    else
    {
		cout<<"飞船A无法追上飞船B"<<endl;
	}
    }
	return 0;
    
} 