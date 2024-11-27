#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct table
{
    int num;
    int age;
    char gender;
    table *next;
};
table *head=NULL;
table *s,*p;
void * create(int n) //建立单链表
{
    

        s=new table;
        for(int i=0;i<n;i++)
        {
            cin>>s->num>>s->age>>s->gender;
            if(head==NULL) head=s;
            else p->next=s;
            p=s;
            s=new table; 
        }
    
    if(p!=NULL) p->next=NULL;
    //delete s;
    return 0;
}
void read(table *head,ostringstream &output) //遍历函数
{
    table *t=head;
    while(t!=NULL)
    {
        output<<t->num<<" "<<t->age<<" "<<t->gender<<endl;
        t=t->next;
    }
}
void statistic(table *head,ostringstream &output)
{
    int nm=0,nf=0;
    table *t=head;
    while(t!=NULL)
    {
        if(t->gender=='m') nm+=1;
        else nf+=1;
        t=t->next;
    }
    output<<"Number of male employees:" <<nm<<endl;
    output<<"Number of female employees:"<<nf<<endl;

}
void dele(table *&head,int n)
{
    table *s1=head,*p1;
    for(int i=1;i<n&&s1!=NULL;i++)
    {
        s1=s1->next; //s1前驱
    }
    p1=s1->next; //应删
    s1->next=p1->next;
    delete p1;
    p1=NULL;
}
void clear(table *&head)
{
    table *current=head,*next;
    while(current!=NULL)
    {
        next=current->next;
        delete current;
        current = next;
    }
    head=NULL;
}
int main()
{
    ostringstream output;
    string stored;
    int n=0,m=0;
    while(cin>>n)
    {
    create(n);
    read(head,output);
    cin>>m;
    create(m);
    read(head,output);
    statistic(head,output);
    dele(head,2);
    read(head,output);
    clear(head);
    string stored = output.str();
    cout<<stored;
    }
}