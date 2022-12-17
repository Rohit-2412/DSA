#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// this algo is based upon greedy approach
int n, m;
const int N = 1e5 + 3;
const int INF = 1e9;
vvi g[N];
vi dist(N), parent(N);
vector<bool> vis(N);
int cost = 0;

void primsMST(int source)
{
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    set<vector<int>> s;
    dist[source] = 0;

    s.insert({0, source});

    // {wt,source}
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << endl;
        cost += w;
        for (auto it : g[x[1]])
        {
            if (vis[it[0]])
                continue;

            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    primsMST(0);
    cout << cost;
    return 0;
}