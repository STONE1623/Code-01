#include<iostream>
#include<cmath>
using namespace std;

struct quad
{
	double a[2];
	double b[2];
	double c[2];
	double d[2];
};

double dist(double a[2],double b[2])
{
	double dist;
	dist = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
	return dist;
}

int main()
{
	quad m;
	while (cin >> m.a[0]>> m.a[1] >> m.b[0] >> m.b[1] >> m.c[0] >> m.c[1] >> m.d[0] >> m.d[1]  )
	{
		if (((dist(m.a, m.b) == dist(m.a, m.d)) && (dist(m.a, m.d) == dist(m.c, m.b)) &&(dist(m.c, m.b)== dist(m.d, m.c)))&&0==((m.b[0]-m.a[0])*(m.d[0]-m.a[0])+ (m.b[1] - m.a[1]) * (m.d[1] - m.a[1])))
		{
			cout << "正方形"  << endl;
		}
		else if ((dist(m.a, m.b) == dist(m.d, m.c)) && (dist(m.a, m.d) == dist(m.c, m.b)) && 0== ((m.b[0] - m.a[0]) * (m.d[0] - m.a[0]) + (m.b[1] - m.a[1]) * (m.d[1] - m.a[1])))
		{
			cout << "矩形" << endl;
		}
		else
		{
			cout << "其他四边形" << endl;
		}
	}
}