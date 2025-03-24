#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;
public:
    void setBox(int a,int b,int c)
    {
        length=a;width=b;height=c;
    }
    int volume()
    {
        return length*width*height;
    }
};
int main()
{
    Box box1;
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        box1.setBox(a,b,c);
        cout<<box1.volume()<<endl;
    }
}