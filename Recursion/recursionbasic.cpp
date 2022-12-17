#include <bits/stdc++.h>
using namespace std;
// p raised to power n
int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    int prevPower = power(n, p - 1);
    return n * prevPower;
}
// factorial of n
int factoriral(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int fact = factoriral(n - 1);
    return n * fact;
}
// nth fibonacci number
int fibonacci(int n)
{
    if (n == 1 || n == 0) //base case
    {
        return n;
    }
    int fib = fibonacci(n - 1) + fibonacci(n - 2);
    return (fib);
}
int main()
{
    int n;
    cin >> n;
    int p;
    cin >> p;
    // cout << power(n,p) <<endl;
    // cout << factoriral(n)<<endl;
    cout <<fibonacci(n)<<endl;
    return 0;
}
