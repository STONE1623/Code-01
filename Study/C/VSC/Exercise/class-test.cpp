#include <iostream>
using namespace std;

class Test
{
    int a=10;
public:
    static int b;
};
int Test::b=20;
int main()
{
    cout<<Test::b;
}