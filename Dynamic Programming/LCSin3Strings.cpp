#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem :
// find length of maximum length of LCS in 3 strings
int N = 205;
vector<vector<vector<int>>> dp(N, vvi(N, vi(N, -1)));

int lcs(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if (i == 0 or j == 0 or k == 0)
        return 0;

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    if (s1[i - 1] == s2[j - 1] and s2[j - 1] == s3[k - 1])
    {
        return 1 + lcs(s1, s2, s3, i - 1, j - 1, k - 1);
    }

    int l = lcs(s1, s2, s3, i - 1, j, k);
    int r = lcs(s1, s2, s3, i, j - 1, k);
    int p = lcs(s1, s2, s3, i, j, k - 1);
    return dp[i][j][k] = max({l, r, p});
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << lcs(s1, s2, s3, s1.size(), s2.size(), s3.size()) << endl;

    return 0;
}