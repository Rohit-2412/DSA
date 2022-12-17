#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 2, MOD = 1e9 + 7;

// to find the indices of the occurences of string s in t(given string)

// Prefix function - it is the length of longest proper prefix substring in S[0..i] which is also a suffix of this substring
// prefix[0] = 0
// prefix[i] = max k such that s[0...k-1] = s[i-(k-1) ... i]

// example : T = abcabcd
// prefix array : 0 0 0 1 2 3

vi prefix_function(string s)
{
    int n = s.size();
    vi pi(n, 0);

    rep(i, 1, n)
    {
        int j = pi[i - 1];

        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    // Time complexity : O(n)
    return pi;
}

int main()
{
    string s = "na";
    vi prefix = prefix_function(s);

    string t = "apna college";
    int pos = -1;
    int i(0), j(0);

    while (i < t.size())
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
        }

        else
        {
            if (j != 0)
                j = prefix[j - 1];

            else
                i++;
        }

        if (j == s.size())
        {
            pos = i - s.size();
            break;
        }
    }
    cout << pos;

    return 0;
}