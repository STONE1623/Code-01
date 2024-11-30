#include <iostream>
using namespace std;

int main()
{
    int year=0,month=1,date=0,day=0;
    //enum mdays1 {jan=31,feb=30,mar=31,apr=30,may=31,jun=30,jul=31,aug=31,sep=30,oct=31,nov=30,dec=31};
    //enum mdays2 {jan=31,feb=30,mar=31,apr=30,may=31,jun=30,jul=31,aug=31,sep=30,oct=31,nov=30,dec=31};
    int mday1[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int mday2[]={31,29,31,30,31,30,31,31,30,31,30,31};
    while(cin>>year>>day)
    {
        while(day>=365)
        {
            if(year%4==0) day-=366;
            else day-=365;
            year+=1;
        }
    if(year%4==0)
    for(int i=0;day>mday2[i];day-=mday2[i],month+=1,i++);

    else
    for(int i=0;day>mday1[i];day-=mday1[i],month+=1,i++);

    cout<<year<<"/"<<month<<"/"<<day<<endl;
    year=0;month=1;day=0;
    }
}