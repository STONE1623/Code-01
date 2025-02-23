#include <iostream>
#include <string>
using namespace std;

struct node {
    int num;
    node* next;
};

struct node* n1 = NULL;
struct node* n2 = NULL;

void cleanlist(node*& head);

void clist(node*& head, string a, int len) {
    struct node* s, * p;
    s = new node;
    
    if (len % 3 == 0) {
        for (int i = len / 3; i > 0; i--) {
            s->num = (a[3 * i - 1] - '0') + 10 * (a[3 * i - 2] - '0') + 100 * (a[3 * i - 3] - '0');
            if (head == NULL) head = s;
            else p->next = s;
            p = s;
            s = new node;
        }
        p->next = NULL;
        delete s;
    }
    
    if (len % 3 != 0) {
        for (int i = len / 3 + bool(len % 3); i > 0; i--) {
            if (i != 1) {  // 非最后一组数
                s->num = (a[3 * i + len % 3 - 4] - '0') + 
                        10 * (a[3 * i + len % 3 - 5] - '0') + 
                        100 * (a[3 * i + len % 3 - 6] - '0');
                if (head == NULL) head = s;
                else p->next = s;
                p = s;
                s = new node;
            } else {
                if (len % 3 == 1) 
                    s->num = a[3 * i + len % 3 - 4] - '0';
                else if (len % 3 == 2) 
                    s->num = (a[3 * i + len % 3 - 4] - '0') + 10 * (a[3 * i + len % 3 - 5] - '0');
                else if (len % 3 == 0) 
                    s->num = (a[3 * i + len % 3 - 4] - '0') + 
                            10 * (a[3 * i + len % 3 - 5] - '0') + 
                            100 * (a[3 * i + len % 3 - 6] - '0');
                if (head == NULL) head = s;
                else p->next = s;
                p = s;
                p->next = NULL;
                delete s;
            }
        }
    }
}

void doplus(node*& n1, node*& n2, string& c) {
    node* p1 = n1;
    node* p2 = n2;
    node* rh = NULL;
    node* rt = NULL;
    int carry = 0;

    while (p1 != NULL || p2 != NULL || carry != 0) {
        int sum = carry;
        if (p1) { sum += p1->num; p1 = p1->next; }
        if (p2) { sum += p2->num; p2 = p2->next; }
        carry = sum / 1000;
        sum %= 1000;

        node* temp = new node;
        temp->num = sum;
        temp->next = NULL;
        if (!rh) rh = rt = temp;
        else {
            rt->next = temp;
            rt = temp;
        }
    }

    c.clear();
    node* prev = NULL;
    node* curr = rh;
    while (curr) {
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    for (node* r = prev; r; r = r->next) {
        if (r != prev) {
            if (r->num < 10) c.push_back('0');
            if (r->num < 100) c.push_back('0');
        }
        c += to_string(r->num);
    }

    cleanlist(rh);
}

void dominus(node*& n1, node*& n2, string& c, int len1, int len2) {
    bool neg = false;
    node* t1 = n1;
    node* t2 = n2;
    
    if (len1 < len2) neg = true;
    else if (len1 == len2) {
        // 位数相同时，需要从高位（链表尾）开始比较
        node* last1 = NULL, * last2 = NULL;
        
        // 找到两个链表的最后一个节点（最高位）
        while (t1) {
            last1 = t1;
            t1 = t1->next;
        }
        while (t2) {
            last2 = t2;
            t2 = t2->next;
        }
        
        // 从高位向低位比较
        t1 = n1;
        t2 = n2;
        while (last1 && last2) {
            if (last1->num < last2->num) {
                neg = true;
                break;
            } else if (last1->num > last2->num) {
                break;
            }
            
            // 找到当前最高位的前一位
            node* prev1 = NULL, * prev2 = NULL;
            t1 = n1;
            t2 = n2;
            while (t1 != last1) {
                prev1 = t1;
                t1 = t1->next;
            }
            while (t2 != last2) {
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
    node* rh = NULL;
    node* rt = NULL;
    int carry = 0;

    while (p1 != NULL || p2 != NULL || carry != 0) {
        int sum = carry;
        if (p1) { sum += p1->num; p1 = p1->next; }
        if (p2) { sum -= p2->num; p2 = p2->next; }
        carry = (sum + 1000) / 1000 - 1;
        sum += 1000;
        sum %= 1000;

        node* temp = new node;
        temp->num = sum;
        temp->next = NULL;
        if (!rh) rh = rt = temp;
        else {
            rt->next = temp;
            rt = temp;
        }
    }

    c.clear();
    if (neg) c.push_back('-');
    
    node* prev = NULL;
    node* curr = rh;
    while (curr) {
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    for (node* r = prev; r; r = r->next) {
        if (r != prev) {
            if (r->num < 10) c.push_back('0');
            if (r->num < 100) c.push_back('0');
        }
        c += to_string(r->num);
        
    }
    
    cleanlist(rh);
}

void readReverse(node* head) {
    if (!head) return;
    readReverse(head->next);
    cout << head->num << " ";
}

void cleanlist(node* &head) {
    while(head){
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    string a, b, c, d;
    int a1, b1;  // 存放a,b的符号
    
    while (cin >> a >> b) {
        // 判断正负，长度
        int len1 = a.length(), len2 = b.length();
        if (a[0] != '-') a1 = 1;
        else a1 = 0;
        if (b[0] != '-') b1 = 1;
        else b1 = 0;

        if (a[0] == '-' || a[0] == '+') {
            len1--;
            string temp;
            for (int i = 0; i < len1; i++) {
                temp += a[i + 1];
            }
            a = temp;
        }
        
        if (b[0] == '-' || b[0] == '+') {
            len2--;
            string temp;
            for (int i = 0; i < len2; i++) {
                temp += b[i + 1];
            }
        }
        
        clist(n1, a, len1);
        clist(n2, b, len2);

        if (a1 == 1 && b1 == 1 || a1 == 0 && b1 == 0) {
            if (a1 == 0 && b1 == 0) c.push_back('-');
            doplus(n1, n2, c);
            cout << c << endl;
        }
        
        if (a1 == 1 && b1 == 0 || a1 == 0 && b1 == 1) {
            if (a1 == 0 && b1 == 1)
                dominus(n2, n1, c, len2, len1);
            else
                dominus(n1, n2, c, len1, len2);
            cout << c << endl;
        }

        // 清理内存
        cleanlist(n1);
        cleanlist(n2);
    }
    return 0;
}