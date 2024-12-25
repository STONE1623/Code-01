#include <iostream>
#include <iomanip>
using namespace std;
int main(){int a[5][5] = { 1 }, i, j, k;for (k = 2, i = 0; i<5; i++)for (j = i; (j <= i + 1) && (j<7); j++, k++)a[j][i] = k;for (i = 0; i<5; i++){for (j = 0; j<5; j++)cout << setw(3) << a[i][j];cout << endl;}}