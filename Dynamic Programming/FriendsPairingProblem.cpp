#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Probelm : given n friends each can remain single or can be paired up with some other friend. each friend can be paired only once. find out total number of ways in which friends can be paired or remain single.

/*
 Idea :
 let f(n) = ways n ppl can be paired or remain single
 for nth person there are two choices
    nth person can reamin single we recur for f(n-1)
    n th person pairs up with any of the remaining n-1 persons
    then :
        f(n) = f(n-1) +(n-1) * f(n-2)


*/

// const int N = 1e4;
// vi dp(N, -1);

// int friends(int n)
// {
//     if (n == 0)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];

//     return dp[n] = friends(n - 1) + (n - 1) * friends(n - 2);
// }

int main()
{
    // int n;
    // cin >> n;

    // dp[0] = 1;
    // dp[1] = 1;

    // cout << friends(n);

    int n;
    cin >> n;

    vi dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    rep(i, 2, n + 1)
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];

    cout << dp[n];
    return 0;
}