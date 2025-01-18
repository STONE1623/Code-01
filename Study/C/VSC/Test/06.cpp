#include <iostream>
using namespace std ;
void Three(int n){int i,t;int num[100];for(i=0,t=n;t!=0;i++){num[i]=t%3;t=t/3;}/*if(0==n) cout<<n;*/for(i=i-1;i>=0;i--){cout<<num[i];}cout<<endl;}int main(){Three(20);}