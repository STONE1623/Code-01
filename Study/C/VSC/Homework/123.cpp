#include <iostream>
#include <sstream>
#include <string>
using namespace std;

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
