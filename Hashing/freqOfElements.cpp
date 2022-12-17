#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
    int n;
    cin >> n;
    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    map<int, int> freq;
    rep(i, 0, a.size())
    {
        freq[a[i]]++;
    }
    map<int, int>::iterator it;

    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->ff << " " << it->ss << endl;
    }

    return 0;
}