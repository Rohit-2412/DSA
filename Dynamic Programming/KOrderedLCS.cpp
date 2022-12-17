#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 2005;
int n, m, k;
vi a, b;
int dp[2005][2005][7];

int solve(int i, int j, int k)
{
    if (i == n or j == m)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int c1(0), c2(0), c3(0);

    if (a[i] == b[j])
        c1 = 1 + solve(i + 1, j + 1, k);

    if (k > 0)
        c2 = 1 + solve(i + 1, j + 1, k - 1);
    c3 = max(solve(i + 1, j, k), solve(i, j + 1, k));

    return dp[i][j][k] = max({c1, c2, c3});
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> k;
    a = vi(n);
    b = vi(m);
    for (auto &i : a)
        cin >> i;

    for (auto &i : b)
        cin >> i;

    cout << solve(0, 0, k);
    return 0;
}