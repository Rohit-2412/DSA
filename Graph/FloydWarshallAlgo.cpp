#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int INF = 1e9;

int main()
{
    vvi graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};
    int n = graph.size();
    vvi dist = graph;

    rep(k, 0, n)
    {
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]) // conditon for checking if the distance is smaller after including any random new edge
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; // relaxation
                }
            }
        }
    }

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << setw(3) << dist[i][j] << " ";
        }
        cout << endl;
    }
    // another way of pritning distance
    // rep(i, 0, n)
    // {
    //     rep(j, 0, n)
    //     {
    //         if (dist[i][j] == INF)
    //             ;
    //         else
    //             cout << "dist[" << i << "][" << j << "] : " << dist[i][j] << endl;
    //     }
    // }

    //
    // if we want distance from any edge "n" to edge "m" then just
    // cout << dist[n][m] << endl;
    // cout << "dist[2][2] : " << dist[2][2] << endl;
    // cout << "dist[2][3] : " << dist[2][3] << endl;
    // cout << "dist[2][1] : " << dist[2][1] << endl;
    // cout << "dist[2][2] : " << dist[2][2] << endl;
    // cout << dist[0][3];

    return 0;
}