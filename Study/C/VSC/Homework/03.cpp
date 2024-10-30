#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int m;
    for(m=1;m<1001;m++)
    {
        
            int i=1;
            k1:if(m%i==0)
            {
                m=m/i;
                if(m!=1) cout<<i<<" ";
                else 
                {
                    cout<<i<<endl;
                break;
                }
            }
            
                
            if(m%i!=0)
            {
                i=i+1;
                goto k1;
            }
        
    }
    return 0;
}