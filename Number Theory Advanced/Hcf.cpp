#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 7, MOD = 1e9 + 7;

// HCF by euclid algorithm
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a = 10, b = 15;
    cout << "GCD(" << a << ", "
         << b << ") = " << gcd(a, b)
         << endl;

    a = 35, b = 10;
    cout << "GCD(" << a << ", "
         << b << ") = " << gcd(a, b)
         << endl;

    a = 31, b = 2;
    cout << "GCD(" << a << ", "
         << b << ") = " << gcd(a, b)
         << endl;

    return 0;
}
