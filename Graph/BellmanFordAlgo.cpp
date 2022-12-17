#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define inf 1e9
// Problem : from source vertex v, find the shortest distance to all other nodes in the graph

// Advantages : it works for Negative edges also
// it can detect negative cycle as well

int main()
{
    // adjacency list for graph

    int n, m;
    cin >> n >> m; // n = nodes // m = edges
    vvi edges;

    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;
    vi dist(n, inf);
    dist[src] = 0;

    rep(i, 0, n - 1)
    {
        bool change = 0; // for cycle detection
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            // condition for cycle detection
            if (dist[v] > w + dist[u])
                change = true;
            dist[v] = min(dist[v], w + dist[u]);
        }
    }

    for (auto i : dist)
        cout << i << " ";
    cout << endl;

    return 0;
}