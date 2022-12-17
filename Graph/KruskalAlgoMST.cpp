#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

// Problem : given an undirected graph G(V,E) a spanning tree of the graph G is a tree that spans (that it includes every vertex of G) and is a subgraph of G(every edge in the tree belongs to G)
// Cost of spanning tree is the sum of Weights of all edges
// there can be multiple ST for one graph.
// not each graph has a ST
// Spanning Trees are not unique

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
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
            continue;

        else
        {
            cout << u << " " << v << "\n";
            cost += w;
            union_sets(u, v);
        }
    }
    cout << "Cost : " << cost << endl;
    return 0;
}
// 8 9
// 1 2 5
// 2 3 6
// 4 3 2
// 1 4 9
// 3 5 5
// 5 6 10
// 6 7 7
// 7 8 1
// 8 5 1