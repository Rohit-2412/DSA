#include <bits/stdc++.h>
using namespace std;
//tiling problem
// no. of ways to tile a area of "2*n" with a tile of "2*1"
int tilingWays(int n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return tilingWays(n - 1) + tilingWays(n - 2);
}

// friends pairing problem
// no . of ways in which n friends can be paired up or left single
int friendsPairing(int n)
{
  if (n == 0 || n == 1 || n == 2)
  {
    return n;
  }
  return friendsPairing(n - 1) + friendsPairing(n - 2) * (n - 1); // n-2 can be paired up in n-1 ways
}
// knapsack
// to fill a bag within weight limit and with maximum value of items
int knapsack(int val[], int wt[], int n, int W)
{
  if (n == 0 || W == 0)
  {
    return 0;
  }
  if (wt[n - 1] > W)
  {
    knapsack(val, wt, n - 1, W);
  }
  return max(knapsack(val, wt, n - 1, W - wt[n - 1] + val[n - 1]), knapsack(val, wt, n - 1, W));
}
int main()
{
  // cout <<tilingWays(8)<<endl;
  // cout << friendsPairing(4) << endl;
  int wt[] = {10, 20, 30};
  int val[] = {100, 50, 150};
  int W = 50;
  cout << knapsack(val, wt, 3, W) << endl;
  return 0;
}
