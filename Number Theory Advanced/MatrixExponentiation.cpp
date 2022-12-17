#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 2, MOD = 1e9 + 7;
// function to multiply two sq. matrices
vvi multiply(vvi &a, vvi &b)
{
    int n = a.size();
    vvi ans(n, vi(n, 0));

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            rep(k, 0, n)
                ans[i][j] += a[i][k] * b[k][j];
        }
    }

    return ans;
}

// function to exponentiate
vvi matrixExponentiate(vvi &a, int n)
{
    if (n == 0)
    {
        int sz = a.size();
        vvi ans(n, vi(sz, 0));
        rep(i, 0, sz)
            ans[i][i] = 1;
        return ans;
    }

    if (n == 1)
        return a;

    vvi temp = matrixExponentiate(a, n / 2); // ans for A ^ n/2
    vvi ans = multiply(temp, temp);          // a^n/2 * a^n/2

    if (n & 1)
        ans = multiply(ans, a); // (if odd number then a^n/2 * a^n/2 * a)

    return ans;
}

int_fast32_t main()
{
    int n = 500;
    // cin >> n;

    vvi a(2, vi(2));

    a = {{1, 1}, {1, 0}};
    // a[0][0] = a[0][1] = a[1][0] = 1;
    // a[1][1] = 0;
    double duration;
    clock_t start, finish;
    /* Measure the duration of an event */
    start = clock();

    vvi ans = matrixExponentiate(a, n); // A raised to n

    // cout << ans[0][1] << endl;
    // cout << ans[1][1] << endl;

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << " seconds \n"
         << endl;

    int sz = ans.size();
    rep(i, 0, sz)
    {
        rep(j, 0, sz)
                cout
            << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
// n-th fibonacci number is at ans[0][1]
// n-1 th at ans[1][1]
// n+1 th at ans[0][0]