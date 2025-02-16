#include <iostream>
#include <string>
using namespace std;

struct node
{
    int num;
    node *next;
};
struct node *n1=NULL,*n2=NULL;

void clist(node * & head,string a,int i,int len)
{
    struct node *s,*p;
    s=new node;
    if(i!=len/3-1) //非最后一组数
    {
        s->num=(a[i*3]-'0')+10*(a[i*3+1]-'0')+100*(a[i*3+2]-'0');
        if(head==NULL) head=s;
        else p->next=s;
        p=s;
    }
    else
    {
        if(len%3==1) s->num=a[i*3]-'0';
        else if(len%3==2) s->num=(a[i*3]-'0')+10*(a[i*3+1]-'0');
        p->next=NULL;
        delete s;
    }
}
void cal(node * & n1,node * & n2,string c)
{

}

int main()
{
    string a,b,c;
    cin>>a>>b;

    //判断正负，长度
    int len1=a.length(),len2=b.length();
    if(a[len1-1]=='-'||a[len1-1]=='+') len1--;
    if(b[len2-1]=='-'||b[len2-1]=='+') len2--;
    int flag1=0;
    for(int i=0;i<len1/3;i++)
    {
        clist(n1,a,i,len1);
    }
    for(int i=0;i<len2/3;i++)
    {
        clist(n2,b,i,len2);
    }


}