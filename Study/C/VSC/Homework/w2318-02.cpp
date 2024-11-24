#include <iostream>
using namespace std;

unsigned power2(unsigned number,unsigned pow)
{
    number<<=pow;
    if(number>=sizeof(unsigned)*CHAR_BIT) return 0;
    else
    return number;
}
int main()
{
    unsigned number=0,pow=0;
    while(cin>>number>>pow)
    {
        cout<<power2(number,pow)<<endl;
    }
}