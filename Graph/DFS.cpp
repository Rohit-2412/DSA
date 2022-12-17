#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 2;
bool vis[N];
vi adj[N];

void dfs(int node)
{
    // preorder
    vis[node] = 1;
    cout << node << " ";

    // inorder
    vi ::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        // if not visited then call the dfs again
        if (!vis[*it])
            dfs(*it);
    }
}

int main()
{
    // vertices and edges
    int n, m;
    cin >> n >> m;

    // initializing the visited array to false
    rep(i, 0, n + 1)
        vis[i] = false;

    // taking input of edges
    int x, y;
    rep(i, 0, m)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // pass the node from where we have to start the traversal
    dfs(1);
    return 0;
}