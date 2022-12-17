#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define N 1e7
// Problem : Given an undirected graph. find the single source shortest path from a vertex u to all the vertices in the graph.
// if the node is unreachable then print -1
// the weights of the edges must be positive

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1, N);
    // vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;
    dist[source] = 0;

    set<pair<int, int>> s;
    // {wt,vertex}
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);

        for (auto it : graph[x.second])
        {
            //          v           weight
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // cout << dist[i] << " ";

        if (dist[i] < N)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    cout << 1 << endl;

    return 0;
}