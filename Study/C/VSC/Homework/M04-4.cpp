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
    bool neg=false;
    node* t1=n1;
    node* t2=n2;
    //比较大小
    if(len1<len2) neg=true;
    else if(len1==len2){
    // 位数相同时，需要从高位（表链尾）开始较比
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
    cout<<neg<<endl;

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
    
    if(neg) c+='-';
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
    
    // 创建结果链表
   /* node* rh = nullptr;
    node* rt = nullptr;*/
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
    // 处理被除数小于除数的情况// 处理被除数小于除数的情况
    if(len1 < len2) {
        c = "0";
        savetostring(n1, f);tring(n1, f);
        return;
    }

    // 创建索引数组
    node** index1 = new node*[len1/3 + bool(len1%3)];ode** index1 = new node*[len1/3 + bool(len1%3)];
    node** index2 = new node*[len2/3 + bool(len2%3)]; node*[len2/3 + bool(len2%3)];  // 修正长度计算
    
    // 填充被除数索引
    node* p = n1;ode* p = n1;
    for(int i = 0; i < len1/3 + bool(len1%3); i++) {= 0; i < len1/3 + bool(len1%3); i++) {
        index1[i] = p;
        p = p->next;   p = p->next;
    }

    // 存储商的链表
    node* result = nullptr;
    node* result_tail = nullptr; result_tail = nullptr;
    int len3 = len1 - len2;

    // 从高位开始除 0; i--) {
    for(int i = len3; i >= 0; i--) {
        // 构造当前除数
        string b4 = b;
        b4.append(i, '0');
        cleanlist(n2); = b4.length();
        int nlen2 = b4.length();
        clist(n2, b4, nlen2);
        
        // 当前位的商
        int digit = 0;nt j = 0; j < nlen2/3 + bool(nlen2%3); j++) {
        
        // 试商过程 = p->next;
        while(compare(index1, index2, len1, nlen2)) {
            digit++;
            // 执行减法
            int carry = 0; = 0;
            for(int j = 0; j < len1/3 + bool(len1%3); j++) {x2, len1, nlen2)) {
                int diff = index1[j]->num - index2[j]->num - carry;
                if(diff < 0) {
                    carry = 1;
                    diff += 1000;
                } else {nt j = 0; j < len1/3 + bool(len1%3); j++) {
                    carry = 0;]->num - index2[j]->num - carry;
                }   if(diff < 0) {
                index1[j]->num = diff;rry = 1;
            }           diff += 1000;
        }           } else {
        carry = 0;
        // 保存当前位的商
        node* temp = new node;            index1[j]->num = diff;
        temp->num = digit;            }
        temp->next = nullptr;       }
        if(!result) {        
            result = result_tail = temp;
        } else {temp = new node;
            result_tail->next = temp;
            result_tail = temp;
        }
    }   result = result_tail = temp;
    
    // 保存商和余数>next = temp;
    savetostring(result, c);  // 保存商   result_tail = temp;
    savetostring(n1, f);      // 保存余数   }
    
    // 清理内存
    delete[] index1;   // 保存商和余数
    delete[] index2;;
}   savetostring(n1, f);  // n1 中现在存储的就是余数

bool compare(node** index1, node** index2, int len1, int len2) {// 清理内存
    // 从高位开始比较
    for(int i = len1/3 + bool(len1%3) - 1; i >= 0; i--) {
        if(index1[i]->num < index2[i]->num) {
            return false;
        }ool compare(node** index1, node** index2, int len1, int len2) {
        else if(index1[i]->num > index2[i]->num) {    // 从高位开始比较
            return true;i >= 0; i--) {
        }index1[i]->num < index2[i]->num) {
    }
    // 所有位都相等的情况
    return false;  // 或者根据业务需求返回truedex1[i]->num > index2[i]->num) {
}
void cleanlist(node* &head)
{
    while(head)
    {eturn false;  // 或者根据业务需求返回true
        node* temp=head;
        head=head->next;ode* &head)
        delete temp;
    }
}

void savetostring(node* &head, string &c) {ead=head->next;
    // 反转链表
    node* prev = nullptr;
    node* curr = head;
    while (curr) {
        node* next = curr->next;void savetostring(node* &head, string &c) {
        curr->next = prev;
        prev = curr;   node* prev = nullptr;
        curr = next;;
    } {
    // 格式化为字符串ext;
    //c.clear();t = prev;
    for(node* r = prev; r; r = r->next) {
        if(r != prev) {       curr = next;
            if(r->num < 10) c.push_back('0');    }
            if(r->num < 100) c.push_back('0');为字符串
        }   //c.clear();
        c += to_string(r->num);r = r->next) {
    }    if(r != prev) {
    cleanlist(head);f(r->num < 10) c.push_back('0');
}< 100) c.push_back('0');
   }
void readReverse(node* head)num);
{
    if(!head) return;    cleanlist(head);
    // 先递归访问后续节点
    readReverse(head->next);
    // 回溯时再输出当前节点readReverse(node* head)
    cout << head->num << " ";
}
归访问后续节点
int main()eadReverse(head->next);
{
    string a,b,c,d,f,a2,b2;out << head->num << " ";
    
    //存放小数的位数
    while(cin>>a2>>b2))
    {
    int a1,b1;  //存放a,b的符号2;
    int a3=0,b3=0;  //存放a,b的小数位数
/存放小数的位数
    //去除逗号，存进a,b中
    for(int i=0;i<a2.length();i++)
    {nt a1,b1;  //存放a,b的符号
        if(a2[i]!=','){;  //存放a,b的小数位数
            a+=a2[i];
        }
    }i<a2.length();i++)
    for(int i=0;i<b2.length();i++)
    {a2[i]!=','){
        if(b2[i]!=','){
            b+=b2[i];
        }
    }0;i<b2.length();i++)
    bool ismul=0,isdiv=0;    {
    if(b[0]=='*')
    {
        b=b.substr(1);
        ismul=1;
    };
    if(b[0]=='/')f(b[0]=='*')
    {
        b=b.substr(1);
        isdiv=1;
    }
    //记录正负值f(b[0]=='/')
    if(a[0]!='-') a1=1;    {
    else a1=0;ubstr(1);
    if(b[0]!='-') b1=1;    isdiv=1;
    else b1=0;

    //查找、记录小数点位置并从a,b中去除
    size_t pos = a.find('.');
    if(pos != string::npos) {=1;
        a3 = a.length() - pos - 1;lse b1=0;
        a.erase(pos, 1);
    }//查找、记录小数点位置并从a,b中去除
    size_t pos2 = b.find('.');pos = a.find('.');
    if(pos2 != string::npos) {
        b3 = b.length() - pos2 - 1;s - 1;
        b.erase(pos2,1);   a.erase(pos, 1);
    }
('.');
    //在a,b后补零f(pos2 != string::npos) {
    s2 - 1;
    int dot=0;(pos2,1);
    if(ismul==0&&isdiv==0){
    if(a3>b3) b.append(a3-b3,'0');
    if(b3>a3) a.append(b3-a3,'0');    //在a,b后补零
    dot=a3>b3?a3:b3;
    }
    else dot=a3+b3;v==0){
        if(a3>b3) b.append(a3-b3,'0');
    //去除正负号
    int len1=a.length(),len2=b.length();:b3;
    if(a[0]=='-'||a[0]=='+')
    {
        len1--;
        a = a.substr(1);
    }len2=b.length();
    if(b[0]=='-'||b[0]=='+')
    {   len2--;
        b=b.substr(1);
    }   a = a.substr(1);

    //转化为链表
    clist(n1,a,len1);--;
    clist(n2,b,len2);

    cout<<"ismul: "<<ismul<<" a1: "<<a1<<" b1: "<<b1<<endl;
    //根据符号分类进行运算/转化为链表
    if(ismul==0&&isdiv==0){t(n1,a,len1);
    if(a1==1&&b1==1||a1==0&&b1==0)list(n2,b,len2);
    {
        if(a1==0&&b1==0) c+='-';<"ismul: "<<ismul<<" a1: "<<a1<<" b1: "<<b1<<endl;
        doplus(n1,n2,c);
        if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
    }
    if(a1==1&&b1==0||a1==0&&b1==1)
    {1==0&&b1==0) c+='-';
        if(a1==0&&b1==1)oplus(n1,n2,c);
        dominus(n2,n1,c,len2,len1);
        else
        dominus(n1,n2,c,len1,len2);==1&&b1==0||a1==0&&b1==1)
        if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
    }        if(a1==0&&b1==1)
    },len1);
    else
    {   dominus(n1,n2,c,len1,len2);
        if(ismul==1)th()-dot,".");
        {
            if(a1==1&&b1==0||a1==0&&b1==1) c.push_back('-');
            domul(n1,n2,c,len1,len2);
            if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
        }if(ismul==1)
        else   {
        {||a1==0&&b1==1) c.push_back('-');
            if(a1==1&&b1==0||a1==0&&b1==1) c.push_back('-');2,c,len1,len2);
            dodiv(n1,n2,c,f,b,len1,len2);   if(a3!=0||b3!=0) c.insert(c.length()-dot,".");
        }
    }lse

    //给整数部分添加逗号并删除小数部分末尾多余的0   if(a1==1&&b1==0||a1==0&&b1==1) c.push_back('-');
    if(dot==0)
    {
        for(int i=c.length()-1;i>=0;i--)
        {
            if((c.length()-i)%3==0&&i!=0) c.insert(i,",");
        }
    }
    else   for(int i=c.length()-1;i>=0;i--)
    {        {
        int i=c.length()-1;        if((c.length()-i)%3==0&&i!=0) c.insert(i,",");
        for(;i>=0;i--)
        {
            if(c[i]=='.') break;lse
        }
        for(int j=i-1;j>=0;j--)ngth()-1;
        {   for(;i>=0;i--)
            if((i-j)%3==0&&j!=0) c.insert(j,",");;
        }]=='.') break;
        for(int j=c.length()-1;j>i;j--)
        {t j=i-1;j>=0;j--)
            if(c[j]=='0') c.pop_back();
            else break;       if((i-j)%3==0&&j!=0) c.insert(j,",");;
        }        }
    }       for(int j=c.length()-1;j>i;j--)
















}    }    c.clear();    b.clear();    a.clear();    cleanlist(n2);    cleanlist(n1);    }        f.clear();        cout<<c<<"~~~"<<f<<endl;    {    if(isdiv==1)    if(isdiv!=1) cout<<c<<endl;            {
            if(c[j]=='0') c.pop_back();
            else break;
        }
    }

    
    if(isdiv!=1) cout<<c<<endl;
    if(isdiv==1)
    {
        cout<<c<<"~~~"<<f<<endl;
        f.clear();
    }
    cleanlist(n1);
    cleanlist(n2);
    a.clear();
    b.clear();
    c.clear();
    }

}