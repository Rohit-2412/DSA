#include <bits/stdc++.h>
using namespace std;
int multiplyTwoNumbers(int a, int b)
{
    int result = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            result += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return result;
}
int main()
{
    cout << multiplyTwoNumbers(75, 4) << endl;
    cout << multiplyTwoNumbers(90, 9) << endl;
    cout << multiplyTwoNumbers(83, 66) << endl;
    return 0;
}