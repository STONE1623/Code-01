#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;


int main()
{
    for(int m=6;m<1001;m++)
    {
        int sum=0;
        for(int i=1;i<m;)
        {
            if(m%i==0)
            {
                sum=sum+i;
                i++;
            }
            else i++;
        }
        if(sum==m)
        cout<<sum<<endl;
    }
    return 0;           
}