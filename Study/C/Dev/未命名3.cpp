#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int p=0,q=0,r=0;
	int i=0,j=0,k=0;
	cin>>p>>q>>r;
	
	for(int p1=p;p1>0;i++) p1/=10;  //得出数字位数为i-1 
	for(int q1=p;q1>0;j++) q1/=10;
	for(int r1=p;r1>0;k++) r1/=10;
	int i1=i,j1=j,k1=k; 
	int *P=new int[i-1];int *Q=new int[j-1];int *R=new int[k-1];
	int b=0;
	for(i=0;p>0;i++)
	{
		P[i]=p%10;
		p/=10;
	}
	for(j=0;q>0;j++)
	{
		Q[i]=p%10;
		q/=10;
	}
	for(k=0;r>0;k++)
	{
		R[i]=p%10;
		r/=10;
	}
	int sum1=0,sum2=0,sum3=0;
	for(b=2;b<3;b++)
	{
		for(int i2=0;i2<=i1;i2++)
		{
			sum1+=pow(static_cast<double>(P[i2]),static_cast<double>(i2));
		}
		if(sum1>0) break;
	}
	cout<<sum1;
	for(int q=0;q<=i1;q++) cout<<P[q]<<" ";
}
