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

    int len = sqrtl(n) + 1;
    vi b(len); // array for storing blocks sum

    rep(i, 0, n)
        b[i / len] += a[i];

    int q; // no of queries
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--; // 0 base indexing

        int sum = 0;

        for (int i = l; i <= r;)
        {
            if (i % len == 0 and i + len - 1 <= r)
            {
                sum += b[i / len];
                i += len;
            }

            else
            {
                sum += a[i];
                i++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}