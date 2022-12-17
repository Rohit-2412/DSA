#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// problem : you are gievn an increasing aray
// find length of longest increasing subsequence
const int N = 1e3 + 2;

// overlapping substructure
// vi dp(N, -1);
// int lis(vi &a, int n)
// {
//     if (dp[n] != -1)
//         return dp[n];

//     dp[n] = 1; // if array has one element then it will be a lis of size 1

//     rep(i, 0, n)
//     {
//         if (a[n] > a[i])
//             dp[n] = max(dp[n], 1 + lis(a, i));
//     }

//     return dp[n];
// }
int main()
{
    // int n;
    // cin >> n;

    // vi a(n);
    // rep(i, 0, n)
    //         cin >>
    //     a[i];

    // cout << lis(a, n - 1) << endl;

    int n;
    cin >> n;

    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vi dp(n, 1);

    int ans = 0;

    rep(i, 1, n)
    {
        rep(j, 0, i)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}