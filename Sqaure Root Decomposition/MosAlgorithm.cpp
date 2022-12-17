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
int rootN;
struct Q
{
    int l, r, idx;
};

bool compare(Q q1, Q q2)
{
    if (q1.l / rootN == q2.l / rootN)
        return q1.r > q2.r;

    else
        return q1.l / rootN < q2.l / rootN;
}
Q q[N]; // array of queries

// offline processing used here
// first store the queries
// then sort them on the basis of their l and r occurences (compare function)
// then compute answers and display them in order of there occurences
int main()
{
    int n;
    cin >> n;
    rootN = sqrtl(n) + 1;
    vi a(n);

    rep(i, 0, n)
            cin >>
        a[i];

    int t; // number of test cases
    cin >> t;

    rep(i, 0, t) // storing queries
    {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q, q + t, compare);

    vi ans(t); // ans vector
    int l, r, curr_l = 0, curr_r = -1;
    int curr_ans = 0;
    rep(i, 0, t)
    {
        l = q[i].l;
        r = q[i].r;
        l--;
        r--;

        while (curr_r < r)
        {
            curr_r++;
            curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += a[curr_l];
        }

        while (curr_l < l)
        {
            curr_ans -= a[curr_l];
            curr_l++;
        }

        while (curr_r > r)
        {
            curr_ans -= a[curr_r];
            curr_r--;
        }
        ans[q[i].idx] = curr_ans;
    }

    rep(i, 0, t)
    {
        cout << ans[i] << endl;
    }

    return 0;
}