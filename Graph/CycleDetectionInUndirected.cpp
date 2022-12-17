#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

bool isCycle(int src, vvi &adj, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto neighbour : adj[src])
    {
        if (neighbour != parent)
        {
            // if neighbour is already visited and it is not the parent of the current node
            // cycle is present
            if (visited[neighbour])
                return true;

            // if neighbour is not visited then call the dfs again
            if (!visited[neighbour] && isCycle(neighbour, adj, visited, src))
            {
                return true;
            }
        }
    }
    return false;
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
    bool cycle = 0;

    vector<bool> visited(n, false);

    rep(i, 0, n)
    {
        if (!visited[i] and isCycle(i, adj, visited, -1))
        {
            cycle = true;
        }
    }

    if (cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;

    return 0;
}