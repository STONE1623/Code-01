#include <iostream>
#include <string>
using namespace std;

class Book
{
    int number;
public:
    string bookname;
    int price;
    Book(string a,int b,int c):bookname(a),price(b),number(c) {}
    void display()
    {
        cout<<bookname<<endl<<price<<endl<<number<<endl;
    }
    void borrow()
    {
        number-=1;
        cout<<number<<endl;
    }
    void restore()
    {
        number+=1;
        cout<<number<<endl;
    }
};
int main()
{
    Book book1("book",32,1000);
    book1.display();
    char temp1,temp2;
    cout<<"b/r:"<<endl;
    do
    {
        cin>>temp1;
        if(temp1=='n') break;
        else
        {
            if(temp1=='b') book1.borrow();
            else book1.restore();
        }
        cout<<"y/n:"<<endl;
        cin>>temp2;
        if(temp2=='n') temp2=0;
        else cout<<"b/r:"<<endl;
    }
    while(temp2);
    book1.display();
}