#include <iostream>
using namespace std;

class nauticalmile_kilometer
{
public:
    double kilometer;
    double meter;
    double mile;
    nauticalmile_kilometer(int a,int b):kilometer(a),meter(b),mile(0) {}
    void print()
    {
        cout<<mile<<"\n";
    }
    operator double()
    {

    }
};