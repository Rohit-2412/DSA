#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 6;
vi parent(N);
vi size(N);

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    // adjacency list for graph

    int n, m;
    cin >> n >> m; // n = nodes // m = edges
    vvi adj(n);

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    return 0;
}