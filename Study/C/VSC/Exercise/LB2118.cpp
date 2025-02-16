#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int flag = s2.find(s1);
    if (flag != string::npos)
        cout << s1 << " is substring of " << s2 << endl;
    else 
    
    {
        int flag2 = s1.find(s2);
        if (flag2 == string::npos)
            cout << "No substring" << endl;
        else
            cout << s2 << " is substring of " << s1 << endl;
    }
}