#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
/* we are given an array of wt and val of items
we have to find the max value of elements we can take
{{{here we can take same item again and again}}}
*/

int main()
{
    int n = 5, W = 11;
    // cin >> n;
    vi wt = {3, 2, 4, 5, 1};
    vi val = {4, 3, 5, 6, 1};

    vi dp(W + 1, 0);

    for (int j = 0; j <= W; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j - wt[i] >= 0)
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }

    cout << dp[W];

    return 0;
}