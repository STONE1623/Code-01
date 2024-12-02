#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int num=0;
    while(cin>>num)
    {
        int times=0;
        for(int i=0;i<num;i++)
        {
            //cout<<"第"<<i<<endl;
            string line;
            vector<int> numbers;
            //cin.ignore();
            getline(cin,line);
            istringstream iss(line);
            string number;
            int p=0;
            while(iss>>number)
            {
                numbers.push_back(stoi(number));
                p+=1;
            }
            /*for(int num:numbers)
            {
                cout<<num<<" ";
            }*/
            for(int j=0;j<=p;j++)
            {
                int flag=0;
                for(int k=j+1;k<=p;k++)
                {
                    if(numbers[j]==numbers[k])
                    {
                        flag=1;
                        //cout<<numbers[j]<<" "<<numbers[k]<<" "<<flag<<endl;
                        numbers.erase(numbers.begin()+k);
                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<numbers[j-1]<<endl;
                    break;
                }                
            }
            times+=1;
            if(times==num) break;
            
        }
    }
}