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
    rep(i, 0, N)
        make_set(i);

    // adjacency list for graph

    int n, m;
    cin >> n >> m; // n = nodes // m = edges
    vvi edges;

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    bool cycle = false;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
            cycle = true;

        else
        {
            union_sets(u, v);
        }
    }
    if (cycle)
        cout << "Cycle is present"
             << "\n";

    else
        cout << "Cycle is not present"
             << "\n";

    return 0;
}