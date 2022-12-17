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

struct grp
{

    long pref, suff, sum, ans;
};

int a[N];
grp tree[4 * N];

void build(int node, int st, int end)
{
    if (st == end)
    {
        if (a[st] <= 0)
        {
            tree[node] = grp({0, 0, a[st], 0});
        }

        else
        {
            tree[node] = grp({a[st], a[st], a[st], a[st]});
        }
        return;
    }

    int mid = (st + end) / 2;

    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;

    tree[node].pref = max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);

    tree[node].suff = max(tree[2 * node + 1].suff, tree[2 * node + 1].sum + tree[2 * node].suff);

    tree[node].ans = max({tree[2 * node].suff + tree[2 * node + 1].pref, tree[2 * node].ans, tree[2 * node + 1].ans});
}

void update(int node, int st, int end, int idx, int val)
{
    if (st == end)
    {
        a[st] = val;
        if (a[st] <= 0)
        {
            tree[node].sum = a[st];
            tree[node].pref = tree[node].suff = tree[node].ans = 0;
        }

        else
        {
            tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = a[st];
        }
        return;
    }

    int mid = (st + end) / 2;

    if (idx <= mid)
        update(2 * node, st, mid, idx, val);

    else
        update(2 * node + 1, mid + 1, end, idx, val);

    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;

    tree[node].pref = max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);

    tree[node].suff = max(tree[2 * node + 1].suff, tree[2 * node + 1].sum + tree[2 * node].suff);

    tree[node].ans = max({tree[2 * node].suff + tree[2 * node + 1].pref, tree[2 * node].ans, tree[2 * node + 1].ans});
}

int main()
{
    int n, m;
    cin >> n >> m;

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);
    cout << tree[1].ans << endl;

    while (m--)
    {
        int idx, val;
        cin >> idx >> val;
        update(1, 0, n - 1, idx, val);
        cout << tree[1].ans << endl;
    }
    
    return 0;
}