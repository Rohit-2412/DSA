#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int get_comp(int idx, vector<bool> &vis, vvi &adj)
{
    if (vis[idx])
    {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i, vis, adj);
            vis[i] = true;
        }
    }
    return ans;
}

int main()
{ // adjacency list for graph

    int n, m;
    cin >> n >> m; // n = nodes // m = edges
    vvi adj(n);
    vector<bool> vis(n, 0);

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi components;
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            components.push_back(get_comp(i, vis, adj));
        }
    }

    // for (auto i : components)
    //     cout << i << " ";

    // Question : there are N friends numbered 0 to n -1
    // you have to choose 2 person such that they are not realated to each other.
    // we are given info in form of pairs (x,y) i.e there is a link between x and y
    // find out number of ways in which 2 persons can be choosen from 2 different groups

    long long ans = 0;

    for (auto i : components)
    {
        ans += i * (n - i);
    }

    cout << ans / 2 << endl; // div by 2 to avoid over counting

    return 0;
}