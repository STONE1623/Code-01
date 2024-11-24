#include<iostream>
using namespace std;
void insert( int a[],int,int );
int main()
{
 int a[] = { 10, 12, 23, 25, 48, 48, 53, 58, 60, 78 };
  int x,n,i;
  //cout << "please input insert data: ";
  while(cin >> x)
  {
  n = sizeof(a)/sizeof(int);        //求数组长度
  insert( a, n, x );                 //插入元素
  for( i=0; i<n-1; i++ )
    cout << a[i] << " ";
cout <<a[i-1]<<endl;
  }
}
void insert( int a[],int n,int x )
{
 int i,p,j;
  if ( x<a[n-1] )
  {
 for( i=1; i<n; i++ )         //查找插入位置
      if( x<a[i] )
{
  p=i; break;
}
       for( j=n-1; j>=p; j-- )        //后移元素，挤出最大值
          a[j] = a[j-1];
       a[p] = x;                    //插入元素
  }
}