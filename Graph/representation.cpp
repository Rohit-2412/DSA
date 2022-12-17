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

vi adj[N];
// representation of graphs
int main()
{
    int n, m;
    // cin >> n >> m; // n = nodes // m = edges

    // adjacency matrix
    // vvi adjm(n + 1, vi(n + 1, 0)); // sq. mtx

    // rep(i, 0, m)
    // {
    //     int x, y;
    //     cin >> x >> y;

    //     adjm[x][y] = 1; // edges from x to y is present
    //     adjm[y][x] = 1; // edges from y to x is present
    // }
    // cout << "Adjacency matrix of graph is given by :" << endl;

    // rep(i, 1, n + 1)
    // {
    //     rep(j, 1, n + 1)
    //             cout
    //         << adjm[i][j] << " ";
    //     cout << endl;
    // }

    // // to check for edge

    // if (adjm[3][7])
    // {
    //     cout << "there is a edge between 3 & 7" << endl;
    // }
    // else
    // {
    //     cout << "there is no edge between 3 & 7" << endl;
    // }

    // adjacency list for graph

    cin >> n >> m;  // n = nodes // m = edges

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "adjacency list of above graph is given by :" << endl;

    rep(i, 1, n + 1)
    {
        cout << i
             << "-> ";

        vector<int>::iterator it;

        for (it = adj[i].begin(); it != adj[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}

// test case :
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