#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
问题G: 单链表中有相同值的结点及其个数
题目描述
设有说明语句:
struct List { int data; List * next; };
List *head;
head是有序单向链表的头指针。请编写函数:
void Count( List * head );
计算并输出链表中有相同值的结点及其个数。例如，若数据序列为:
2 3 3 3 4 5 5 6 6 6 6 7 8 9 9
则输出结果为:
data number
3     3
5     2    
6     4
9     2

可以用例 5-18 的程序生成有序链表，测试 Count 函数。
输入
一个链表的长度（也就是链表中有多少个数据），需要存进链表的数据（注意输入的数据要是升序）
输出
相同值的节点及其个数（中间以一个空格间隔）
样例输入 Copy
5
1 1 1 2 2
8
1 1 2 2 2 3 3 3
样例输出 Copy
1 3
2 2
1 2
2 3
3 3*/
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