#include <iostream>
#include <iomanip>
using namespace std;

class nauticalmile_kilometer
{
public:
    double kilometer;
    double meter;
    nauticalmile_kilometer() {}
    nauticalmile_kilometer(int a,int b):kilometer(a),meter(b){}
    void print()
    {
        cout<<kilometer<<"\n"<<meter<<"\n";
    }
    operator double()
    {
        double mile;
        mile=(kilometer+0.001*meter)/1.852;
        return mile;
    }
};
int main()
{
    int a, b;
    while(cin>>a>>b)
    {
        nauticalmile_kilometer n1(a,b);
        cout<<fixed<<setprecision(4)<<double(n1)<<endl;
    }
}