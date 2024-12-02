#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
问题F：单向链表的操作
题目描述
建立一个结点包括职工的编号、年龄和性别的单向链表，分别定义函数完成以下功能：(1).根据输入职工的个数n(n >= 2)建立一个单链表；(2).遍历该链表输出全部职工信息；(3).分别统计男、女职工的人数；(4).在链表尾部插入新职工结点；(5).删除指定编号(此处默认删除第2个员工)的职工结点；编程实现以上函数要求。
输入
每一组输入有如下内容：
初始链表员工的个数n，接着输入员工的相关信息(性别表示：男：‘m’。女：‘f’)。
插入到链表尾部的员工的个数m，再输入待插入的各员工的信息。
输出
输出根据n建立的链表的各员工的信息。
输出插入m个员工后的链表中各员工的信息，并输出此时男女员工的个数。
输出删除指定编号后的链表各员工的信息。
样例输入 Copy
2
1 20 m
2 30 f
2
3 34 m
4 41 f
样例输出 Copy
1 20 m
2 30 f
1 20 m
2 30 f
3 34 m
4 41 f
Number of male employees:2
Number of female employees:2
1 20 m
3 34 m
4 41 f
提示
多组输入。*/
struct table {
    int num;
    int age;
    char gender;
    table *next;
};

table* head = NULL;  // 定义链表头
table *s, *p;

void create(int n) {  // 建立单链表
    for (int i = 0; i < n; i++) {
        s = new table;
        cin >> s->num >> s->age >> s->gender;
        s->next = NULL;
        if (head == NULL) {
            head = s;  // 链表为空时，新节点就是头节点
        } else {
            p->next = s;  // 否则将前一个节点的next指向新节点
        }
        p = s;  // p指向新节点，准备连接下一个节点
    }
}

void read(table *head, ostringstream &output) {  // 遍历链表并输出
    table *t = head;
    while (t != NULL) {
        output << t->num << " " << t->age << " " << t->gender << endl;
        t = t->next;
    }
}

void statistic(table *head, ostringstream &output) {  // 统计男女员工数
    int nm = 0, nf = 0;
    table *t = head;
    while (t != NULL) {
        if (t->gender == 'm') nm++;
        else nf++;
        t = t->next;
    }
    output << "Number of male employees: " << nm << endl;
    output << "Number of female employees: " << nf << endl;
}

void dele(table *&head, int n) {  // 删除第n个节点
    if (head == NULL) return;  // 空链表，直接返回
    table *s1 = head, *p1;
    if (n == 1) {  // 删除头节点
        head = s1->next;
        delete s1;
        return;
    }
    for (int i = 1; i < n - 1 && s1 != NULL; i++) {  // 定位到第n-1个节点
        s1 = s1->next;
    }
    if (s1 == NULL || s1->next == NULL) return;  // 如果没有第n个节点，直接返回
    p1 = s1->next;  // p1指向要删除的节点
    s1->next = p1->next;
    delete p1;
}

void clear(table *&head) {  // 清空链表
    table *current = head, *next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

int main() {
    ostringstream output;
    string stored;
    int n = 0, m = 0;

    while (cin >> n) {  // 读取每组数据的长度
        create(n);  // 创建第一个链表
        read(head, output);  // 输出链表内容
        cin >> m;  // 读取第二个链表的长度
        create(m);  // 创建第二个链表
        read(head, output);  // 输出链表内容
        statistic(head, output);  // 输出统计信息
        dele(head, 2);  // 删除第二个节点
        read(head, output);  // 删除后输出链表内容
        clear(head);  // 清空链表
    }

    stored = output.str();  // 保存输出内容
    cout << stored;  // 输出所有结果

    return 0;
}
