#include<iostream>
#include<cmath>
using namespace std;
 
int main()
{
	int a, b, c, n;
	int x = 100;
	do
	{
		a = x % 10;
		b = x / 10 % 10;
		c = x / 100 % 10;
		if (x == pow(a,3) + pow(b,3) + pow(c,3))
			cout << x <<endl;
		x++;
	} while (x <= 999);
	return 0;
}