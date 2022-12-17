#include <bits/stdc++.h>
using namespace std;
/*  

in this problem we have to find all the possible permutations of a number
which we can do by fixing a number and swaping the rest elements one by one 

now for duplicate elements if after swapping we get the same result we will skip that permutation

*/
// for distinct elements
vector<vector<int>> ans;
void permutation(vector<int> &a, int idx)
{
  if (idx == a.size())
  {
    ans.push_back(a);
    return;
  }
  for (int i = idx; i < a.size(); i++)
  {
    swap(a[i], a[idx]);
    permutation(a, idx + 1);
    swap(a[i], a[idx]);
  }
  return;
}
void helper(vector<int> a, vector<vector<int>> &ans, int idx)
{
  if (idx == a.size())
  {
    ans.push_back(a);
  }
  for (int i = idx; i < a.size(); i++)
  {
    if (i != idx and a[i] == a[idx])
    {
      continue;
    }
    swap(a[i], a[idx]);
  }
}
  vector<vector<int>> permute(vector<int> nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
  }

  int main()
  {
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (auto &i : a)
    // {
    //   cin >> i;
    // }

    // permutation(a, 0);
    // for (auto v : ans)
    // {
    //   for (auto i : v)
    //     cout << i << " ";
    //   cout << "\n";
    // }

    // shortcut way

    // int num;
    // cin >> num;
    // vector<int> a(num);
    // for (auto &i : a)
    // {
    //   cin >> i;
    // }
    // sort(a.begin(), a.end());
    // do
    // {
    //   ans.push_back(a);
    // } while (next_permutation(a.begin(), a.end()));
    // for (auto v : ans)
    // {
    //   for (auto i : v)
    //     cout << i << " ";
    //   cout << "\n";
    // }

    // for duplicate elements
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
      cin >> i;
    }
    vector<vector<int>> res = permute(a);
    for (auto i : a)
    {
      cout << i << " ";
      cout << "\n";
    }
    return 0;
  }
