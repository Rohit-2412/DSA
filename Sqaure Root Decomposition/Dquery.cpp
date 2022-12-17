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
// to display the number of distinct elements in a given range using Mo's Algorithm

struct Q
{
    int l, r, idx;
};
Q q[N];

bool compare(Q q1, Q q2)
{
    if (q1.l / rootN == q2.l / rootN)
        return q1.r > q2.r;

    else
        return q1.l / rootN < q2.l / rootN;
}

int main()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rootN = sqrtl(n);

    int t; // queries
    cin >> t;

    rep(i, 0, t)
    {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q, q + t, compare);

    vi ans(t); // ans vector
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    vi freq(N, 0);

    rep(i, 0, t)
    {
        l = q[i].l, r = q[i].r;
        l--;
        r--;

        while (curr_r < r)
        {
            curr_r++;
            freq[a[curr_r]]++;
            if (freq[a[curr_r]] == 1)
                curr_ans++;
        }

        while (curr_l > l)
        {
            curr_l--;
            freq[a[curr_l]]++;
            if (freq[a[curr_l]] == 1)
                curr_ans++;
        }

        while (curr_l < l)
        {
            freq[a[curr_l]]--;
            if (freq[a[curr_l]] == 0)
                curr_ans--;
            curr_l++;
        }

        while (curr_r > r)
        {
            freq[a[curr_r]]--;
            if (freq[a[curr_r]] == 0)
                curr_ans--;
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