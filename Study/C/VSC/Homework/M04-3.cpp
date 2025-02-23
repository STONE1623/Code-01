#include <iostream>
#include <string>
using namespace std;


struct node
{
    int num;
    node *next;
};
void cleanlist(node*& head);
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
    cleanlist(rh);
}
void cleanlist(node* &head)
{
    while(head)
    {
        node* temp=head;
        head=head->next;
        delete temp;
    }
}
void dominus(node * & n1,node * & n2,string& c,int len1,int len2)
{
    bool neg=false;
    node* t1=n1;
    node* t2=n2;
    if(len1<len2) neg=true;
    else if(len1==len2){
    // 位数相同时，需要从高位（链表尾）开始比较
    
    node *last1 = NULL, *last2 = NULL;
    
    // 找到两个链表的最后一个节点（最高位）
    while(t1) {
        last1 = t1;
        t1 = t1->next;
    }
    while(t2) {
        last2 = t2;
        t2 = t2->next;
    }
    
    // 从高位向低位比较
    t1 = n1;
    t2 = n2;
    while(last1 && last2) {
        if(last1->num < last2->num) {
            neg = true;
            break;
        }
        else if(last1->num > last2->num) {
            break;
        }
        // 找到当前最高位的前一位
        node *prev1 = NULL, *prev2 = NULL;
        t1 = n1;
        t2 = n2;
        while(t1 != last1) {
            prev1 = t1;
            t1 = t1->next;
        }
        while(t2 != last2) {
            prev2 = t2;
            t2 = t2->next;
        }
        last1 = prev1;
        last2 = prev2;
    }
    }

    // 根据比较结果选择减法顺序
    node* p1 = neg ? n2 : n1;  // 被减数取较大值
    node* p2 = neg ? n1 : n2;  // 减数取较小值
        
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
    if(neg) c.push_back('-');
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
    cleanlist(rh);
}


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
    string a,b,c,d,a2,b2;
    int a1,b1;//存放a,b的符号
    //存放小数的位数
    while(cin>>a2>>b2)
    {
    int a3=0,b3=0;
    //判断正负，长度
    //去除，号
    for(int i=0;i<a2.length();i++)
    {
        if(a2[i]!=','){
            a+=a2[i];
        }
    }
    cout<<"a:"<<a<<endl;
    for(int i=0;i<b2.length();i++)
    {
        if(b2[i]!=','){
            b+=b2[i];
        }
    }

    int len1=a.length(),len2=b.length();
    if(a[0]!='-') a1=1;
    else a1=0;
    if(b[0]!='-') b1=1;
    else b1=0;
    //查找小数点位置
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='.') a3=a.length()-i-1;
    }
    if(a3!=0) a.erase(a.length()-a3-1,1);
    for(int i=0;i<b.length();i++)
    {
        if(b[i]=='.') b3=b.length()-i-1;
    }
    if(b3!=0) b.erase(b.length()-b3-1,1);
    if(a3>b3) b.append(a3-b3,'0');
    if(b3>a3) a.append(b3-a3,'0');
    int dot=0;
    dot=a3>b3?a3:b3;
    cout<<"a3: "<<a3<<"   "<<"b3: "<<b3<<endl;
    cout<<"a: "<<a<<"   "<<"b: "<<b<<endl;

    if(a[0]=='-'||a[0]=='+')
    {
        len1--;
        a = a.substr(1);
    }
    if(b[0]=='-'||b[0]=='+')
    {   len2--;
        b=b.substr(1);
    }
    cout<<"去符号"<<endl<<"a3: "<<a3<<"   "<<"b3: "<<b3<<endl;
    cout<<"a: "<<a<<"   "<<"b: "<<b<<endl;
    len1=a.length(),len2=b.length();
    clist(n1,a,len1);
    clist(n2,b,len2);
    cout<<"转链表"<<endl;
    readReverse(n1);cout<<endl;
    readReverse(n2);cout<<endl;
    if(a1==1&&b1==1||a1==0&&b1==0)
    {
        if(a1==0&&b1==0) c.push_back('-');
        doplus(n1,n2,c);
        if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
    }
    if(a1==1&&b1==0||a1==0&&b1==1)
    {
        if(a1==0&&b1==1)
        dominus(n2,n1,c,len2,len1);
        else
        dominus(n1,n2,c,len1,len2);
        if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
    }
    if(dot==0)
    {
        for(int i=c.length()-1;i>=0;i--)
        {
            if((c.length()-i)%3==0&&i!=0) c.insert(i,",");
        }
    }
    else
    {
        int i=c.length()-1;
        for(;i>=0;i--)
        {
            if(c[i]=='.') break;
        }
        for(int j=i-1;j>=0;j--)
        {
            if((i-j)%3==0&&j!=0) c.insert(j,",");;
        }
    }
    cout<<c<<endl;
    cleanlist(n1);
    cleanlist(n2);
    a.clear();
    b.clear();
    }

}