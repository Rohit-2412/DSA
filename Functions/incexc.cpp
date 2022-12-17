#include <bits/stdc++.h>
using namespace std;
int divisible(int num, int a, int b)
{
    int c1 = num / a;
    int c2 = num / b;
    int c3 = num / (a * b);
    return (c1 + c2 - c3);
}
// numbers between 1 and n divisible by two numbers a and b
int main()
{
    int number;
    cin >> number;
    int a, b;
    cin >> a >> b;
    cout << divisible(number,a,b) << endl;
    return 0;
}
