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

int main()
{
    rep(i, 0, N)
    {
        vis[i] = 0;
    }

    //  n = vertices, m = edges
    int n, m;
    cin >> n >> m;

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();

        q.pop();

        cout << node << endl;

        vector<int>::iterator it;

        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }

    return 0;
}
/*
7 7
1 2
1 3
2 4
2 5
2 6
7 3
2 7
*/