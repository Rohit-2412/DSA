#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
    int n = 10;
    // cin >> n;

    vi a(n);
    a = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    int x;
    cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;

    rep(i, 0, n)
    {
        ans += x / a[i];
        x -= x / a[i] * a[i];
    }

    cout << ans << endl;

    return 0;
}