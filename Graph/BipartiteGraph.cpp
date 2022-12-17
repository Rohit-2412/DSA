#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

vvi adj;
vi col;
vector<bool> vis;
bool bipart;

void color(int u, int curr) // current color
{
    if (col[u] != -1 and col[u] != curr)
    {
        bipart = false;
        return;
    }
    
    col[u] = curr;
    if (vis[u])
        return;

    vis[u] = true;

    for (auto i : adj[u])
    {
        color(i, curr xor 1);
    }
}

int main()
{
    bipart = true;
    // adjacency list for graph

    int n, m;
    cin >> n >> m; // n = nodes // m = edges

    adj = vvi(n);
    vis = vector<bool>(n, false);
    col = vi(n, -1);

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    rep(i, 0, n)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }
    if (bipart)
        cout << "Graph is bipartite." << endl;
    else
        cout << "Graph is not bipartite." << endl;

    return 0;
}