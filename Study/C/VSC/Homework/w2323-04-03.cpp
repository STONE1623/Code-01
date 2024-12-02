#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int num=0;
    while(cin>>num)
    {
        string line;
        getline(cin,line);
        int arr[100];
        stringstream ss(line);
        string n;int i=0;
        while(ss>>n)
        {
            arr[i++]=stoi(n);
        }
        for(int j=0;j<=i;j++) cout<<arr[j]<<" ";
    }
}