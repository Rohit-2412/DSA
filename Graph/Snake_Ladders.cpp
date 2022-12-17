#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem : you are at sq 1 and have to reach sqaure 100.
// you have complete control over the die and can get cany number from 1- 6
// for given ladders and snakes find the minimum number of steps to reach 100

// Idea !
// BFS
// push 1 into queue
// for all possibilites in the dice :
//      check if the next position is ladder or snake or empty
//      mark the sqaures as visited ans push into queue
//      stop traversal after you reach 100
int main()
{
    int ladders, snakes;
    cin >> ladders;
    map<int, int> lad;
    map<int, int> snak;
    rep(i, 0, ladders)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v; // ladder 5 to 28
    }
    cin >> snakes;
    rep(i, 0, snakes)
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;

    vi vis(101, 0); // visited vector
                    // so that we dont go to the same sqaure again nd again
    vis[1] = true;

    while (!q.empty() and !found)
    {
        int sz = q.size();

        while (sz-- and !found)
        {
            int t = q.front();
            q.pop();

            for (int die = 1; die <= 6; die++)
            {
                if (t + die == 100)
                    found = true;

                if (t + die <= 100 and lad[t + die] and !vis[t + die])
                {
                    vis[lad[t + die]] = true; // marking visited

                    if (lad[t + die] == 100)
                        found = true;
                    q.push(lad[t + die]);
                }

                else if (t + die <= 100 and snak[t + die] and !vis[snak[t + die]])
                {
                    vis[snak[t + die]] = true;

                    if (snak[t + die] == 100)
                        found = true;
                    q.push(snak[t + die]);
                }

                else if (t + die <= 100 and !vis[t + die] and !snak[t + die] and !lad[t + die])
                {
                    vis[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }

    if (found == true)
        cout << moves << endl;

    else
        cout << -1 << endl;
    return 0;
}