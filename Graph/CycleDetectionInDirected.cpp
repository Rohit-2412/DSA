#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

bool isCycle(int src, vvi &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[src] = true;

    if (!visited[src])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (!visited[i] and isCycle(i, adj, visited, stack))
            {
                return true;
            }
            if (stack[i])
            {
                return true;
            }
        }
    }
    stack[src] = false;
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

    bool cycle = false;
    vector<int> stack(n, 0);
    vector<bool> visited(n, 0);

    rep(i, 0, n)
    {
        if (!visited[i] and isCycle(i, adj, visited, stack))
        {
            cycle = true;
        }
    }

    if (cycle == true)
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    return 0;
}