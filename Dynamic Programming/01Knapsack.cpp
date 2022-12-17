#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem : given an array of items with their {weight,value} and a weight W
// find maximum value which we can be stolen to put into knapsack
// note : we have to take full item or no item.
const int N = 1e3 + 2;
int wt[N], val[N];
// int dp[N][N];
vvi dp(N, vi(N, -1));

int knapsack(int n, int w)
{
    if (w <= 0)
        return 0;
    if (n <= 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] > w)
        dp[n][w] = knapsack(n - 1, w);

    else
        dp[n][w] = max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);

    return dp[n][w];
}
int main()
{
    rep(i, 0, N)
    {
        rep(j, 0, N)
            dp[i][j] = -1;
    }

    int n;
    cin >> n;

    // storing weights of items
    rep(i, 0, n)
    {
        cin >> wt[i];
    }

    // storing values of items
    rep(i, 0, n)
    {
        cin >> val[i];
    }

    int w; // capacity of knapsack
    cin >> w;

    cout << knapsack(n, w) << endl;

    return 0;
}

/*
Problem statement :
we are given an array / list of items with their weights and their worth / value.

we are also given a value W as weight which is our max holding capacity.

now we have to find the max profit which we can make by stealing items from the list/array constraint to our limit of Weight W.

Pseudo Code :

upper bound : the maximum number of items which
int N = (int)1e5;

global array or list to store the profit till now.
int[] dp = new int[N]; // array declaration

int knapSack(int n,int weight)
{

}
*/