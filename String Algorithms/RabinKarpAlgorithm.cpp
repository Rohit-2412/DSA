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
// find the indices of occurences of string s in t
int p = 32;
vi power(N);

int32_t main()
{
    string s = "na";
    string t = "apna collegena";
    int T = t.size();
    int S = s.size();

    power[0] = 1;

    // power calculation
    rep(i, 1, N)
        power[i] = (power[i - 1] * p) % MOD;

    // hash table for string t
    vector<long long> h(T + 1, 0);
    rep(i, 0, T)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % MOD;

    // hash for string s
    long long h_s = 0;
    rep(i, 0, S)
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % MOD;

    // main loop
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] - h[i] + MOD) % MOD;

        if (cur_h == (h_s * power[i]) % MOD)
            cout << "found at index " << i << endl;
    }
    return 0;
}