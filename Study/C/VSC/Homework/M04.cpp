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
        s->num=(a[3*i-1]-'0')+10*(a[3*i-2]-'0')+100*(a[3*i-3]-'0');
        if(head==NULL) head=s;
        else p->next=s;
        p=s;
        s=new node;
        }
        p->next=NULL;
        delete s;
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
void doplus(node * & n1,node * & n2,string& c)
{
    node* p1=n1;
    node* p2=n2;
    node* rh=NULL;
    node* rt=NULL;
    int carry=0;

    while(p1!= NULL||p2!=NULL||carry!=0)
    {
        int sum=carry;
        if(p1) {sum+=p1->num;p1=p1->next;}
        if(p2) {sum+=p2->num;p2=p2->next;}
        carry=sum/1000;
        sum%=1000;

        node* temp=new node;
        temp->num=sum;
        temp->next=NULL;
        if(!rh) rh=rt=temp;
        else{
            rt->next=temp;
            rt=temp;
        }
    }
    c.clear();
    node* prev=NULL;
    node* curr=rh;
    while(curr)
    {
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }


    for(node* r= prev;r;r=r->next)
    {
        if(r!=prev){
        if(r->num<10) c.push_back('0');
        if(r->num<100) c.push_back('0');
        }
        c+=to_string(r->num);
        
    }
    while(rh)
    {
        node* temp=rh;
        rh=rh->next;
        delete temp;
    }
}
void dominus(node * & n1,node * & n2,string& c)
{
    node* p1=n1;
    node* p2=n2;
    node* rh=NULL;
    node* rt=NULL;
    int carry=0;

    while(p1!= NULL||p2!=NULL||carry!=0)
    {
        int sum=carry;
        if(p1) {sum+=p1->num;p1=p1->next;}
        if(p2) {sum-=p2->num;p2=p2->next;}
        carry=(sum + 1000)/1000 - 1;
        sum+=1000;
        sum%=1000;

        node* temp=new node;
        temp->num=sum;
        temp->next=NULL;
        if(!rh) rh=rt=temp;
        else{
            rt->next=temp;
            rt=temp;
        }
    }
    c.clear();
    node* prev=NULL;
    node* curr=rh;
    while(curr)
    {
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }


    for(node* r= prev;r;r=r->next)
    {
        if(r!=prev){
        if(r->num<10) c.push_back('0');
        if(r->num<100) c.push_back('0');
        }
        c+=to_string(r->num);
        
    }
    while(rh)
    {
        node* temp=rh;
        rh=rh->next;
        delete temp;
    }
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
    string a,b,c,d;
    while(cin>>a>>b)
    {
    //判断正负，长度
    int len1=a.length(),len2=b.length();
    if(a[0]=='-'||a[0]=='+')
    {
        len1--;
        string temp;
        for(int i=0;i<len1;i++)
        {
            temp+=a[i+1];
        }
        a=temp;
    }
    if(b[0]=='-'||b[0]=='+')
    {   len2--;
        string btemp;
        for(int i=0;i<len2;i++)
        {
            btemp+=b[i+1];
        }
        b=btemp;
    }
    clist(n1,a,len1);
    clist(n2,b,len2);
    
    //判断大小
    //read
    /*struct node *p,*q;
    p=n1;q=n1;
    read(n1,p,q);*/
    cout<<"len1:"<<len1<<endl;
    cout<<"len2:"<<len2<<endl;
    cout<<"n1:";
    readReverse(n1);
    cout<<endl<<"n2:";
    readReverse(n2);
    cout<<endl;
    if(a[0]=='+'&&b[0]=='+'||a[0]=='-'&&b[0]=='-'||a[0]!='-'&&a[0]!='+'&&b[0]=='+')
    {
        doplus(n1,n2,c);
        cout<<c<<endl;
    }
    while(n1)
    {
        node* temp=n1;
        n1=n1->next;
        delete temp;
    }
    while(n2)
    {
        node* temp=n2;
        n2=n2->next;
        delete temp;
    }
    }

}