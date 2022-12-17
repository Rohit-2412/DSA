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

// for point updates
// vi bit;
// int n;
// void update(int idx, int val)
// {
//     while (idx <= n)
//     {
//         bit[idx] += val;
//         idx += idx & (-idx);
//     }
// }

// int query(int i)
// {
//     int ans = 0;

//     while (i > 0)
//     {
//         ans += bit[i];
//         i -= i & (-i);
//     }

//     return ans;
// }

// for range updates

int query(int i, int bit[], int n)
{
    int ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= i & (-i);
    }
    return ans;
}

void update(int i, int inc, int bit[], int n)
{
    while (i <= n)
    {
        bit[i] += inc;
        i += i & (-i);
    }
}
int main()
{
    //--- point update (to update the val at a[i] and to find the sum of a[l..r]) ---//

    // cin >> n;
    // bit = vi(n + 1);
    // vi a(n + 1);
    // rep(i,1,n+1)
    // {
    //     cin >> a[i];
    //     update(i, a[i]);
    // }

    // int q;
    // cin >> q;

    // while(q--)
    // {
    //     int c;
    //     cin >> c;

    //     if(c==1)
    //     {
    //         int l, r;
    //         cin >> l >> r;
    //         int ans = query(r) - query(l-1);
    //         cout<<ans<<"\n";
    //     }

    //     else if(c==2)
    //     {
    //         int idx, val;
    //         cin >> idx >> val;

    //         update(idx, -a[idx]);
    //         a[idx] = val;
    //         update(idx, val);
    //     }
    // }

    //--- range updates : to add the val in range l to r of the array ---//
    // query : to get the value stored at a[l]

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int bit[n + 10] = {0};
        int u;
        cin >> u;

        while (u--)
        {
            int l, r, inc;
            cin >> l >> r >> inc;
            l++;
            r++; // for shifting base indexing to 1 base indexing

            update(l, inc, bit, n);  // A[L..] + inc
            update(r+1, -inc, bit, n); // A[...R] -inc
        }

        int q;
        cin >> q;

        while (q--)
        {
            int w;
            cin >> w;
            w++;

            cout << query(w, bit, n) << endl;
        }
    }

    return 0;
}