#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e3, INF = 1e9 + 2;

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];

    vi jump(n, INF); // dp table

    if (a[0] == 0)
    {
        cout << "INF" << endl;
        return 0;
    }

    jump[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + a[j]))
            {
                jump[i] = min(jump[i], jump[j] + 1);
            }
        }
    }

    cout << jump[n-1] << endl;

    return 0;
}