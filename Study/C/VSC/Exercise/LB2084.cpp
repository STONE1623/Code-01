#include <iostream>
using namespace std;

int main()
{
	int p=0,q=0,r=0;
	int i=0,j=0,k=0;
	cin>>p>>q>>r;
	
	for(;p>0;i++) p/=10;
	int i1=i=1;
	int *P=new int[i1];
	for(i=0;p>0;i++)
	{
		P[i]=p%10;
		p/=10;
	}
	for(int q=0;q<i;q++) cout<<P[q]<<" ";
}