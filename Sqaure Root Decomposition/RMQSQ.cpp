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

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];

    int len =(int) sqrtl(n) + 1;
    vi b(len, MOD); // array for storing blocks max value

    rep(i, 0, n)
        b[i / len] = min(b[i / len], a[i]);

    int q; // no of queries
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // l--, r--; // 0 base indexing

        int ans = MOD; // very big value

        for (int i = l; i <= r;)
        {
            if (i % len == 0 and i + len - 1 <= r)
            {
                ans = min(ans, b[i / len]);
                i += len;
            }

            else
            {
                ans = min(ans, a[i]);
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}