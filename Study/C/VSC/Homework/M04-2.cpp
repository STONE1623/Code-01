#include <iostream>
#include <string>
using namespace std;
struct node
{
    int num;
    node *next;
};
void cleanlist(node*& head);
void savetostring(node*& head,string& c);
bool compare(node** ,node** ,int,int);
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
    savetostring(rh, c);
}
void dominus(node * & n1,node * & n2,string& c,int len1,int len2)
{
    node** index1 = new node*[len1/3+bool(len1%3)];
    node** index2 = new node*[len2/3+bool(len2%3)];
    node* p = n1;
    for(int i = 0; i < len1/3+bool(len1%3); i++) {
        index1[i] = p;
        p = p->next;
    }
    p = n2;
    for(int i = 0; i < len2/3+bool(len2%3); i++) {
        index2[i] = p;
        p = p->next;
    }
    // 根据比较结果选择减法顺序
    node* p1 = compare(index1,index2,len1,len2) ? n2 : n1;  // 被减数取较大值
    node* p2 = compare(index1,index2,len1,len2) ? n1 : n2;  // 减数取较小值
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
    
    if(!compare(index1,index2,len1,len2)) c+='-';
    savetostring(rh, c);
}
void domul(node* & n1, node* & n2, string& c,int len1,int len2) 
{  

    // 创建两个链表的索引数组
    int len3=len1+len2;
    node** index1 = new node*[len1/3+bool(len1%3)];
    node** index2 = new node*[len2/3+bool(len2%3)];
    node** index3 = new node*[len3/3+bool(len3%3)];
    // 填充索引数组
    node* p = n1;
    for(int i = 0; i < len1/3+bool(len1%3); i++) {
        index1[i] = p;
        p = p->next;
    }
    p = n2;
    for(int i = 0; i < len2/3+bool(len2%3); i++) {
        index2[i] = p;
        p = p->next;
    }
    node* r = nullptr;
    node*s=nullptr,*t=nullptr;
    for(int i=0;i<len3/3+bool(len3%3);i++)
    {
        s=new node;
        s->num=0;s->next=nullptr;
        if(r==NULL) r=s;
        else t->next=s;
        t=s;
        index3[i]=s;
    }
    
    for(int i=0;i<len1/3+bool(len1%3);i++)
    {
        for(int j=0;j<len2/3+bool(len2%3);j++)
        {
            index3[i+j]->num+=index1[i]->num*index2[j]->num;
            if(i+j<len3/3+bool(len3%3)-1) index3[i+j+1]->num+=index3[i+j]->num/1000;
            index3[i+j]->num%=1000;
        }
    }
    if(index3[len3/3+bool(len3%3)-1]->num==0)
    {
        node* temp=index3[len3/3+bool(len3%3)-1];
        index3[len3/3+bool(len3%3)-2]->next=nullptr;
        delete temp;
    }
    
    // 清理索引数组
    delete[] index1;
    delete[] index2;
    delete[] index3;
    
    // 保存结果到字符串
    savetostring(r, c);
}
void dodiv(node* &n1, node* &n2, string& c, string& f, string b, int len1, int len2) 
{
    if(len1 < len2) {
        // 被除数小于除数，商为0，余数为被除数
        c = "0";
        savetostring(n1, f);
        return;
    } else {
        int len3 = len1 - len2;
        
        // 为商字符串预分配足够长度并初始化为0
        c.clear();
        c.assign(len3, '0');
        
        // 创建索引数组
        node** index1 = new node*[len1/3 + bool(len1%3)];
        node** index2 = nullptr;  // 延迟创建，避免内存泄漏
        
        // 填充被除数索引
        node* p = n1;
        for(int i = 0; i < len1/3 + bool(len1%3); i++) {
            index1[i] = p;
            p = p->next;
        }
        
        int nlen2 = len2, nlen1 = len1;
        for(int i = len3; i >= 0; i--) {
            string b4 = b;
            b4.append(i, '0');
            cleanlist(n2);  // 清理之前的n2
            nlen2 = b4.length();
            clist(n2, b4, nlen2);  // 重建n2
            
            // 重新分配索引数组
            delete[] index2;  // 释放之前的内存
            index2 = new node*[nlen2/3 + bool(nlen2%3)];
            
            // 填充除数索引
            p = n2;
            for(int j = 0; j < nlen2/3 + bool(nlen2%3); j++) {
                index2[j] = p;
                p = p->next;
            }
            
            // 试商过程
            while(compare(index1, index2, nlen1, nlen2)) {
                // 商的当前位加1
                c[i]++;  // 使用字符加法
                
                // 执行减法
                int carry = 0;
                for(int j = 0; j < nlen1/3 + bool(nlen1%3); j++) {
                    int sum = carry;
                    if(j < nlen2/3 + bool(nlen2%3)) {
                        sum += (index1[j]->num - index2[j]->num);
                    } else {
                        sum += index1[j]->num;
                    }
                    
                    // 处理借位
                    if(sum < 0) {
                        carry = -1;
                        sum += 1000;
                    } else {
                        carry = 0;
                    }
                    
                    index1[j]->num = sum;
                }
                
                // 去除高位的零
                while(nlen1 > 0 && index1[nlen1/3 + bool(nlen1%3) - 1]->num == 0) {
                    nlen1--;
                }
            }
        }
        
        // 保存余数
        node* remainder = nullptr;
        node* remainder_tail = nullptr;
        
        for(int i = 0; i < nlen1/3 + bool(nlen1%3); i++) {
            if(index1[i]->num != 0 || !remainder) {
                node* temp = new node;
                temp->num = index1[i]->num;
                temp->next = nullptr;
                
                if(!remainder) {
                    remainder = remainder_tail = temp;
                } else {
                    remainder_tail->next = temp;
                    remainder_tail = temp;
                }
            }
        }
        
        // 如果余数为空，添加一个0节点
        if(!remainder) {
            remainder = new node;
            remainder->num = 0;
            remainder->next = nullptr;
        }
        
        // 保存余数到字符串f
        savetostring(remainder, f);
        cleanlist(remainder);
        
        // 删除商中的前导零
        while(c.length() > 1 && c[0] == '0') {
            c.erase(0, 1);
        }
        
        // 清理内存
        delete[] index1;
        delete[] index2;
    }
}

// 修改 compare 函数
bool compare(node** index1, node** index2, int len1, int len2) {
    // 先比较长度
    if(len1/3 + bool(len1%3) > len2/3 + bool(len2%3)) {
        return true;
    }
    if(len1/3 + bool(len1%3) < len2/3 + bool(len2%3)) {
        return false;
    }
    
    // 长度相同时，从高位开始比较
    for(int i = len1/3 + bool(len1%3) - 1; i >= 0; i--) {
        if(index1[i]->num < index2[i]->num) {
            return false;
        }
        else if(index1[i]->num > index2[i]->num) {
            return true;
        }
    }
    // 所有位都相等的情况
    return true;  // 修改这里，相等时返回 true
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

void savetostring(node* &head, string &c) {
    // 反转链表
    node* prev = nullptr;
    node* curr = head;
    while (curr) {
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    // 格式化为字符串
    //c.clear();
    for(node* r = prev; r; r = r->next) {
        if(r != prev) {
            if(r->num < 10) c.push_back('0');
            if(r->num < 100) c.push_back('0');
        }
        c += to_string(r->num);
    }
    cleanlist(head);
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
    string a,b,c,d,f,a2,b2;
    
    //存放小数的位数
    while(cin>>a2>>b2)
    {
    int a1,b1;  //存放a,b的符号
    int a3=0,b3=0;  //存放a,b的小数位数

    //去除逗号，存进a,b中
    for(int i=0;i<a2.length();i++)
    {
        if(a2[i]!=','){
            a+=a2[i];
        }
    }
    for(int i=0;i<b2.length();i++)
    {
        if(b2[i]!=','){
            b+=b2[i];
        }
    }
    bool ismul=0,isdiv=0;
    if(b[0]=='*')
    {
        b=b.substr(1);
        ismul=1;
    }
    if(b[0]=='/')
    {
        b=b.substr(1);
        isdiv=1;
    }
    //记录正负值
    if(a[0]!='-') a1=1;
    else a1=0;
    if(b[0]!='-') b1=1;
    else b1=0;

    //查找、记录小数点位置并从a,b中去除
    size_t pos = a.find('.');
    if(pos != string::npos) {
        a3 = a.length() - pos - 1;
        a.erase(pos, 1);
    }
    size_t pos2 = b.find('.');
    if(pos2 != string::npos) {
        b3 = b.length() - pos2 - 1;
        b.erase(pos2,1);
    }

    //在a,b后补零
    int dot=0;
    if(ismul==0&&isdiv==0){
    if(a3>b3) b.append(a3-b3,'0');
    if(b3>a3) a.append(b3-a3,'0');
    dot=a3>b3?a3:b3;
    }
    else dot=a3+b3;
    
    //去除正负号
    int len1=a.length(),len2=b.length();
    if(a[0]=='-'||a[0]=='+')
    {
        len1--;
        a = a.substr(1);
    }
    if(b[0]=='-'||b[0]=='+')
    {   len2--;
        b=b.substr(1);
    }

    //转化为链表
    clist(n1,a,len1);
    clist(n2,b,len2);

    //根据符号分类进行运算
    if(ismul==0&&isdiv==0){
    if(a1==1&&b1==1||a1==0&&b1==0)
    {
        if(a1==0&&b1==0) c+='-';
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
    }
    else
    {
        if(ismul==1)
        {
            if(a1==1&&b1==0||a1==0&&b1==1) c.push_back('-');
            domul(n1,n2,c,len1,len2);
            if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
        }
        else
        {
            if(a1==1&&b1==0||a1==0&&b1==1) c.push_back('-');
            dodiv(n1,n2,c,f,b,len1,len2);
        }
    }

    //给整数部分添加逗号并删除小数部分末尾多余的0
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
        for(int j=c.length()-1;j>i;j--)
        {
            if(c[j]=='0') c.pop_back();
            else break;
        }
    }

    if(isdiv!=1) cout<<c<<endl;
    if(isdiv==1)
    {
        if(!f.empty()) cout<<c<<"~~~"<<f<<endl;
        else cout<<c<<endl;
        f.clear();
    }
    cleanlist(n1);
    cleanlist(n2);
    a.clear();
    b.clear();
    c.clear();
    }
}