#include <iostream>
#include <string>
using namespace std;

struct node
{
    int num;
    node *next;
};
struct node *n1=NULL,*n2=NULL;

void clist(node * & head,string a,int len)
{
    struct node *s,*p;
    s=new node;
    if(len%3==0)
    {
        for(int i=len/3;i>0;i--)
        {
        s->num=(a[3*i+len%3-4]-'0')+10*(a[3*i+len%3-5]-'0')+100*(a[3*i+len%3-6]-'0');
        if(head==NULL) head=s;
        else p->next=s;
        p=s;
        s=new node;
        }
    }
    

    if(len%3!=0){
    for(int i=len/3+bool(len%3);i>0;i--)
    {
    if(i!=1) //非最后一组数
    {
        s->num=(a[3*i+len%3-4]-'0')+10*(a[3*i+len%3-5]-'0')+100*(a[3*i+len%3-6]-'0');
        if(head==NULL) head=s;
        else p->next=s;
        p=s;
        s=new node;
    }
    else
    {
        if(len%3==1) s->num=a[3*i+len%3-4]-'0';
        else if(len%3==2) s->num=(a[3*i+len%3-4]-'0')+10*(a[3*i+len%3-5]-'0');
        else if(len%3==0) s->num=(a[3*i+len%3-4]-'0')+10*(a[3*i+len%3-5]-'0')+100*(a[3*i+len%3-6]-'0');
        if(head==NULL) head=s;
        else p->next=s;
        s->next=NULL;
    }
    }
    }
}
void cal(node * & n1,node * & n2,string c)
{

}

/*void read(node *head,node * & p,node * & q)
{
    if(p->next!=NULL)
    {
        int a=p->num;
        q=p;
        p=p->next;
        read(head,p,q);
        cout<<a<<" ^";
    }
    if(p->next==NULL)
    {
        cout<<p->num<<" & ";
    }
}*/


void readReverse(node* head)
{
    if(!head) return;
    // 先递归访问后续节点
    readReverse(head->next);
    // 回溯时再输出当前节点
    cout << head->num << " ";
}

int main()
{
    string a,b,c;
    cin>>a>>b;

    //判断正负，长度
    int len1=a.length(),len2=b.length();
    if(a[0]=='-'||a[0]=='+') len1--;
    if(b[0]=='-'||b[0]=='+') len2--;
    int flag1=0;
    clist(n1,a,len1);
    clist(n2,b,len2);
    
    //read
    /*struct node *p,*q;
    p=n1;q=n1;
    read(n1,p,q);*/
    cout<<"len1:"<<len1<<endl;
    cout<<"len2:"<<len2<<endl;
    cout<<endl;
    //cout<<n1->num<<endl;
    readReverse(n1);


}