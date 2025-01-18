#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int array[] = {16,29,30,46};
    int index = 0;
    while (index<4) 
    {
        int n = array[index];
        int base = 9;
        int sum = 0;
        int i;
        for (i = 1; i <= 8; i++) 
        {
            sum += base*i;
            if (!(n / sum)) 
            {
                sum -= base*i;
                break;
            }
            base *= 10;
        }
        int over_digit = n - sum;
        int count = over_digit / i;
        int count_mod = over_digit % i;
        int start = pow(10, i - 1) + count - 1;
        if (count_mod != 0) 
        {
            start++;
            for (int k = 1; k <= i - count_mod; k++)
            {
                start /= 10;
            }
        }
        cout << start % 10 << endl;index++;
        index++;
    }
}