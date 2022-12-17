#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
  int n, k;
  cin >> n >> k;

  vi a(n);

  // taking elements into vector
  rep(i, 0, n)
  {
    cin >>
        a[i];
  }

  map<int, int> freq;

  rep(i, 0, n)
  {
    int presentSize = freq.size();

    if (freq[a[i]] == 0 && presentSize == k)
      break;

    freq[a[i]]++;
  }

  vii ans;

  map<int, int>::iterator it;

  for (it = freq.begin(); it != freq.end(); it++)
  {
    if (it->ss != 0)
    {
      pii x;
      x.ff = it->ss;
      x.ss = it->ff;
      ans.push_back(x);
    }
  }

  sort(ans.begin(), ans.end(), greater<pii>());

  vii::iterator it1;

  for (it1 = ans.begin(); it1 != ans.end(); it1++)
  {

    cout << it1->ss << " " << it1->ff << endl;
  }

  return 0;
}