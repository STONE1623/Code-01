#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* next;
};

// 解析输入的数字字符串，提取符号并构建链表
void parse_number(const string& s, char* sign, Node** head);
// 比较两个链表表示的数字的绝对值大小
int compare_abs(Node* a, Node* b);
// 判断链表表示的数字是否为零
bool is_zero(Node* head);
// 实现两个链表表示的数字相加
Node* add(Node* a, Node* b);
// 实现两个链表表示的数字相减
Node* subtract(Node* a, Node* b);
// 反转链表
Node* reverse_list(Node* head);
// 去除链表头部的前导零
Node* trim_zeros(Node* head);
// 复制链表
Node* copy_list(Node* head);
// 打印链表表示的数字
void print_number(Node* head);
// 释放链表占用的内存
void free_list(Node* head);

//主函数
int main() {
    string num1, num2;
    cout << "please input the first number:";
    cin >> num1;
    char sign1;
    Node* num1_head = nullptr;
    parse_number(num1, &sign1, &num1_head);

    cout << "please input the next number:";
    cin >> num2;
    char sign2;
    Node* num2_head = nullptr;
    parse_number(num2, &sign2, &num2_head);

    cout << "please select the operator(+ or -):";
    char op;
    cin >> op;

    Node* result_head = nullptr;
    char result_sign = '+';

    if (op == '+') {
        if (sign1 == sign2) {
            result_sign = sign1;
            result_head = add(num1_head, num2_head);
        } else {
            int cmp = compare_abs(num1_head, num2_head);
            if (cmp >= 0) {
                result_sign = sign1;
                result_head = subtract(num1_head, num2_head);
            } else {
                result_sign = (sign2 == '+') ? '-' : '+';
                result_head = subtract(num2_head, num1_head);
            }
        }
    } else if (op == '-') {
        char new_sign2 = (sign2 == '+') ? '-' : '+';
        if (sign1 == new_sign2) {
            result_sign = sign1;
            result_head = add(num1_head, num2_head);
        } else {
            int cmp = compare_abs(num1_head, num2_head);
            if (cmp >= 0) {
                result_sign = sign1;
                result_head = subtract(num1_head, num2_head);
            } else {
                result_sign = (new_sign2 == '+') ? '-' : '+';
                result_head = subtract(num2_head, num1_head);
            }
        }
    } else {
        cout << "error" << endl;
        free_list(num1_head);
        free_list(num2_head);
        return 1;
    }

    if (is_zero(result_head)) {
        result_sign = '+';
    }

    cout << "result:";
    if (result_sign == '-') {
        cout << '-';
    }
    print_number(result_head);

    free_list(num1_head);
    free_list(num2_head);
    free_list(result_head);

    return 0;
}

// 解析输入的数字字符串，提取符号并构建链表
void parse_number(const string& s, char* sign, Node** head) {
    *head = nullptr;
    if (s.empty()) {
        *sign = '+';
        return;
    }

    int start = 0;
    *sign = '+';
    if (s[0] == '+' || s[0] == '-') {
        *sign = s[0];
        start = 1;
    }

    string num_str = s.substr(start);
    num_str.erase(remove(num_str.begin(), num_str.end(), ','), num_str.end());

    if (num_str.empty() || num_str.find_first_not_of("0123456789") != string::npos) {
        *sign = '+';
        *head = new Node{0, nullptr};
        return;
    }

    reverse(num_str.begin(), num_str.end());

    Node* tail = nullptr;
    for (size_t i = 0; i < num_str.size(); i += 3) {
        string group = num_str.substr(i, 3);
        reverse(group.begin(), group.end());
        int value = stoi(group);
        Node* newNode = new Node{value, nullptr};
        if (!*head) {
            *head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// 比较两个链表表示的数字的绝对值大小
int compare_abs(Node* a, Node* b) {
    int len_a = 0, len_b = 0;
    Node* temp_a = a;
    Node* temp_b = b;

    // 计算链表 a 的长度
    while (temp_a) {
        len_a++;
        temp_a = temp_a->next;
    }
    // 计算链表 b 的长度
    while (temp_b) {
        len_b++;
        temp_b = temp_b->next;
    }

    if (len_a > len_b) return 1;
    if (len_a < len_b) return -1;

    // 反转链表 a 和 b
    a = reverse_list(a);
    b = reverse_list(b);

    temp_a = a;
    temp_b = b;

    // 逐位比较
    while (temp_a) {
        if (temp_a->value > temp_b->value) {
            a = reverse_list(a);
            b = reverse_list(b);
            return 1;
        }
        if (temp_a->value < temp_b->value) {
            a = reverse_list(a);
            b = reverse_list(b);
            return -1;
        }
        temp_a = temp_a->next;
        temp_b = temp_b->next;
    }

    // 恢复链表 a 和 b 的原始顺序
    a = reverse_list(a);
    b = reverse_list(b);

    return 0;
}

// 判断链表表示的数字是否为零
bool is_zero(Node* head) {
    while (head) {
        if (head->value != 0) return false;
        head = head->next;
    }
    return true;
}

// 实现数字相加
Node* add(Node* a, Node* b) {
    Node* result = nullptr;
    Node** p = &result;
    int carry = 0;
    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->value; a = a->next; }
        if (b) { sum += b->value; b = b->next; }
        carry = sum / 1000;
        *p = new Node{sum % 1000, nullptr};
        p = &((*p)->next);
    }
    return result;
}

// 实现数字相减
Node* subtract(Node* a, Node* b) {
    Node* result = nullptr;
    Node** p = &result;
    int borrow = 0;
    while (a || b) {
        int val_a = (a ? a->value : 0) - borrow;
        int val_b = (b ? b->value : 0);
        borrow = 0;
        if (val_a < val_b) {
            val_a += 1000;
            borrow = 1;
        }
        *p = new Node{val_a - val_b, nullptr};
        p = &((*p)->next);
        if (a) a = a->next;
        if (b) b = b->next;
    }
    return trim_zeros(result);
}

// 反转链表
Node* reverse_list(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// 去除链表头部的零
Node* trim_zeros(Node* head) {
    if (!head) return nullptr;
    Node* reversed = reverse_list(head);
    while (reversed->next && reversed->value == 0) {
        Node* temp = reversed;
        reversed = reversed->next;
        delete temp;
    }
    return reverse_list(reversed);
}

// 复制链表
Node* copy_list(Node* head) {
    Node dum;
    Node* current = &dum;
    while (head) {
        current->next = new Node{head->value, nullptr};
        current = current->next;
        head = head->next;
    }
    return dum.next;
}

// 打印链表表示的数字
void print_number(Node* head) {
    if (is_zero(head)) {
        cout << "0" << endl;
        return;
    }
    Node* reversed = reverse_list(copy_list(head));
    cout << reversed->value;
    reversed = reversed->next;
    //int count = 0 ;
    while (reversed) {
        cout << ",";
        if (reversed->value < 10) {
            cout << "00";
        } else if (reversed->value < 100) {
            cout << "0";
        }
        cout << reversed->value;
        reversed = reversed->next;
    }
    cout << endl;
    free_list(reversed);
}

// 释放链表占用的内存
void free_list(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}