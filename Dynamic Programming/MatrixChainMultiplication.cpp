#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Probelm : you are given dimensions of N matrix in the form of an array of size n+1
// you have to tell the min number of operations needed to compute their mulitplication
// Example :
//      A = [1,2,3,4]
// dimensions of mtx are 1,2 & 2,3 & 3,4
// if we do B*C then operations = 2*3*4 {resultant mtx dimensions are 2 * 4}
// then A*(BC) operations : 1*2*4
// total 32
// but if we do A*b then AB * C then stepd will be minimized

// overlapping subproblem
const int N = 1e3 + 2, MOD = 1e9 + 7;
int a[N];
// vvi dp(N, vi(N, -1));
// int mcm(int i,int j)
// {
//     if(i == j )
//         return 0;

//     if(dp[i][j] != -1)
//     return dp[i][j];

//     dp[i][j] = MOD;
//     rep(k,i,j)
//     {
//         dp[i][j] = min(dp[i][j], mcm(i, k) + mcm(k + 1, j) + a[i - 1] * a[k] * a[j]);
//     }

//     return dp[i][j];
// }

int main()
{
    // int n;
    // cin >> n;

    // rep(i, 0, n)
    //         cin >>
    //     a[i];

    // cout << mcm(1, n - 1) << endl;

    // tabulation :

    int n;
    cin >> n;

    rep(i, 0, n)
            cin >>
        a[i];

    vvi dp(N, vi(N, MOD)); // dp table

    // marking diagonal elements 0
    rep(i, 1, n)
        dp[i][i] = 0;

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = MOD; // we want to minimize dp[i][j] so maximize it first;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }
        }
    }

    cout << dp[1][n - 1] << endl;

    return 0;
}