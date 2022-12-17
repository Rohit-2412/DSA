#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 3, MOD = 1e9 + 7;
int p = 31;
vector<long long> powers(N);

long long calculate_hash(string s)
{
    long long hash = 0;
    rep(i,0,s.size())
    {
        hash += (s[i] - 'a' + 1) * powers[i];
    }

    return hash;
}

int main()
{
    powers[0] = 1;
    rep(i, 1, N)
        powers[i] = (powers[i - 1] * p) % MOD;

    vector<string> words = {"aa", "ab", "aa", "b", "cc", "aa"};
    vector<long long> hashes;

    for (auto w : words)
        hashes.push_back(calculate_hash(w));

    sort(hashes.begin(), hashes.end());

    int distinct = 0;
    rep(i, 0, hashes.size())
    {
        if (i == 0 or hashes[i] != hashes[i - 1])
            distinct++;
    }

    cout << distinct << endl;
    return 0;
}