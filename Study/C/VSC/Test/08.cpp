#include <iostream>
using namespace std;
#include <ctime>

int main()
{
    srand(time(0));
    cout<<rand()%4<<endl;cout<<rand()%4<<endl;
}