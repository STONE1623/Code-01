#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int arr[26] = {0};
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i])) // 检查是否为字母
            {
                str[i] = tolower(str[i]); // 转换为小写
                arr[str[i] - 'a']++; // 统计字母出现次数
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] > 0)
            {
                cout << char(i + 'a') << ": " << arr[i] << endl;
            }
        }
    }
}