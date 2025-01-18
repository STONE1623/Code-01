#include<iostream>
using namespace std ;
void MysteryFun()
{ 
    char ch ;cin>>ch;
    if (ch>=97&&ch<=117) {ch+= 5;}
    if (ch>=118&&ch<=122) {ch-=21;}
    if ( ch != '.' )MysteryFun() ;
    cout << ch <<endl;
}
int main ()
{
    MysteryFun();
    cout << endl ;
}