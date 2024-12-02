#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
        for(int i=0;i<num;i++)
        {
            char ch;
            int x;
            //map<int,int> mp;
            vector<int> numbers;
            int amount=1;
            while(scanf("%d",&x)!=EOF&&getchar()!='\n')
            {
                numbers.push_back(x);
                amount++;
                //mp[x]++;
            }
            for(int p=0;p<amount;p++)
            {
                int max=numbers[p+1];
                for(int q=p+1;q<amount;q++)
                {
                    if(numbers[q]>max)
                    {
                        max=numbers[q];
                    }
                }
                if(max>numbers[p]) numbers[p]=max;
            }
            for(int p=0;p<amount;p++)
            {
                cout<<numbers[p]<<" ";
            }
            cout<<endl;

        }
    }
}