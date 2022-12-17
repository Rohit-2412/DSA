#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem :
// given an array of n numbers
// find length of maximum subsequence which is increasing then decreasing or entirelt increasing or decreasing
int main()
{
  int n;
  cin >> n;

  vi a(n);

  for (auto &i : a)
    cin >> i;

  vi fwd(n, 1), bwd(n, 1);

  int ans = 0;

  rep(i, 0, n)
  {
    rep(j, 0, i)
    {
      if (a[i] > a[j])
        fwd[i] = max(fwd[i], 1 + fwd[j]);
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j > i; j--)
    {
      if (a[i] > a[j])
        bwd[i] = max(bwd[i], 1 + bwd[j]);
    }
  }

  rep(i, 0, n)
      ans = max(ans, fwd[i] + bwd[i] - 1);

  cout << ans;
  return 0;
}