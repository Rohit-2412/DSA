#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 2, MOD = 1e9 + 7;

// int power(int a, int n)
// {
//     a %= MOD;
//     int ans = 1;

//     while (n > 0)
//     {
//         if (n & 1)
//             ans = (ans * a) % MOD;
//         a = (a * a) % MOD;
//         n = n >> 1;
//     }
//     return ans;
// }

// recursive way:
int power(int a, int n)
{
    if (n == 0)
        return 1;

    int p = power(a, n / 2);

    if (n & 1)
        return (((p * p) % MOD) * a) % MOD;

    else
    {
        return (p * p) % MOD;
    }
}
int main()
{
    int a, n;
    cin >> a >> n;
    a %= MOD;
    cout << power(a, n) << endl;
    return 0;
}