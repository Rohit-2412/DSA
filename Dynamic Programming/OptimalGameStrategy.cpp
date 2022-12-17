#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e3;
int dp[N][N];
vi a;
// Problem : we are given an array of even size 
// there are two players p1 and p2
// first turn is of P1
// he has to choose one element from first or last position of current array 
// then next player P2 will choose one element from remaining array elements

// we have to choose wisely so that we can maximise our chances of winning

// idea:
// we will first store the value of L and R element from array then choose max element
int solve(int i, int j)
{
    if (i == j)
        return a[i];

    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    // if we choose i'th coin
    int l = a[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
    // A[i...j], rem coins = a[i+1,j]

    // if we choose j'th coin
    int r = a[j] + min(solve(i, j - 2), solve(i + 1, j - 1));
    // A[i...j], rem coins = a[i,j-1]
    return dp[i][j] = max(l, r);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    a = vi(n);
    for (auto &i : a)
        cin >> i;

    cout << solve(0, n - 1) << "\n";

    return 0;
}