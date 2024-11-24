#include <iostream>
using namespace std;

struct p
{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
};
struct p p;
int main()
{
    double x1=0,x2=0,y1=0,y2=0,x3=0,y3=0,x4=0,y4=0;
    while(cin>>p.x1>>p.y1>>p.x2>>p.y2>>p.x3>>p.y3>>p.x4>>p.y4)
    {
        double l1=(p.x1-p.x2)*(p.x1-p.x2)+(p.y1-p.y2)*(p.y1-p.y2);
        double l2=(p.x2-p.x3)*(p.x2-p.x3)+(p.y2-p.y3)*(p.y2-p.y3);
        double l3=(p.x3-p.x4)*(p.x3-p.x4)+(p.y3-p.y4)*(p.y3-p.y4);
        double l4=(p.x4-p.x1)*(p.x4-p.x1)+(p.y4-p.y1)*(p.y4-p.y1);
        double d3=(p.x2-p.x4)*(p.x2-p.x4)+(p.y2-p.y4)*(p.y2-p.y4);
        double d4=(p.x3-p.x1)*(p.x3-p.x1)+(p.y3-p.y1)*(p.y3-p.y1);   
        if(y1-y2==y4-y3&&x1-x2==x4-x3&&y1-y4==y2-y3&&x1-x4==x2-x3) //两组对边平行相等
        {
            if(l1+l2==d4&&l1+l4==d3&&l3+l4==d4&&l2+l3==d4)
            {
                if(l1==l2&&l3==l4&&l1==l3) cout<<"正方形"<<endl;
                else cout<<"矩形"<<endl;
            }
            else cout<<"其他四边形"<<endl;
        }     
        else cout<<"其他四边形"<<endl;
    }
}