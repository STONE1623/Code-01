#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct List { string data; List * next; };
List *head;
List *s, *p;

struct Count { string num;int times;Count * next; };
void create(int n) {  // 建立单链表
    for (int i = 0; i < n; i++) {
        s = new List;
        cin >> s->data;
        s->next = NULL;
        if (head == NULL) {
            head = s;  // 链表为空时，新节点就是头节点
        } else {
            p->next = s;  // 否则将前一个节点的next指向新节点
        }
        p = s;  // p指向新节点，准备连接下一个节点
    }
}
Count *s1, *p1;
Count *count1;
void clear(List *&head) {  // 清空链表
    List *current = head, *next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}
void clear(Count *&head) {  // 清空链表
    Count *current = head, *next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}
void count(Count *head1,int num,List *head)
{
    //Count *count;
    List *temp=head;
    while(temp!=NULL)
    {
        if(temp->data=="@") temp=temp->next;
        else{
        List *temp2=temp->next;
        int times=1;
        while(temp2!=NULL)
        {
            if(temp->data==temp2->data) 
            {
                times++;
                temp2->data='@';
            }
            temp2=temp2->next;
        }

        if(times>1)
        {
            s1=new Count;
            s1->num=temp->data;
            s1->times=times;
            s1->next=NULL;
            if(count1==NULL)
            {
                count1=s1;
            }
            else
            {
                p1->next=s1;
            }
            p1=s1;
        }
        temp=temp->next;
        }
    }
}
int main()
{
    int num;
    while(cin>>num)
    {
        //List *s=head->next;
        //List *p=new List;
        create(num);
        List *temp=head;
        count(count1,num,head);
        /*while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }*/
        Count *temp3=count1;
        while(temp3!=NULL)
        {
            cout<<temp3->num<<" "<<temp3->times<<endl;
            temp3=temp3->next;
        }
        clear(head);
        clear(count1);
    }
}