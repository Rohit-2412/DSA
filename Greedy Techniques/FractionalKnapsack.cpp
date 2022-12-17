#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem : Given n items with {weight,value} of each item and the capacity of Sack W
// we need to put these items in knapsack such that the final value of items in knapsack is maximum.

// Approach : we will find the value per kg of each item and then sort it in decreasing order
// then add items til we have enough capacity if we come to a situation where we can't pick full item then we will take some part of it (depending upon weight)

bool compare(pii p1, pii p2)
{
    double v1 = (double)p1.ff / p1.ss;
    double v2 = (double)p2.ff / p2.ss;

    return v1 > v2;
}
int main()
{
    int n;
    cin >> n;
    vii a(n);
    rep(i, 0, n)
    {
        // first value : price
        // second value : weight
        cin >> a[i].ff >> a[i].ss;
    }

    int w;
    cin >> w;
    sort(a.begin(), a.end(), compare);

    // we need to print the maximum amount we can take
    int ans = 0;

    rep(i, 0, n)
    {
        if (w >= a[i].ss)
        {
            ans += a[i].ff;
            w -= a[i].ss;
            continue;
        }

        double vw = (double)a[i].ff / a[i].ss;
        ans += vw * w;
        w = 0;
        break;
    }

    cout << ans << endl;
    return 0;
}
// n = 5
// 21 7
// 24 4
// 12 6
// 40 5
// 30 6
// weight = 20