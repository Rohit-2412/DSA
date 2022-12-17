#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem : find the maximum xor of subarray of a given array
// idea :
// build a tree using binary number conversion of all elements
// then travel in the opposite direction each time to maximise the xor
// 1 xor 1 and 0 xor 0 = 0
// 1 xor 0 = 1
class trie
{
public:
    trie *next[2];
    trie()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

trie *buildTrie(vi &a)
{
    trie *root = new trie();
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        trie *cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (cur->next[bit] == NULL)
                cur->next[bit] = new trie();
            cur = cur->next[bit];
        }
    }
    return root;
}

int helper(trie *root, vi &a)
{
    int res = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        trie *it = root;
        int cur_max = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1) ? 0 : 1;
            if (it->next[bit])
            {
                cur_max <<= 1;
                cur_max |= 1;
                it = it->next[bit];
            }

            else
            {
                cur_max <<= 1;
                cur_max |= 0;
                it = it->next[bit xor 1];
            }
        }
        res = max(cur_max, res);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vi a(n);

    for (auto &i : a)
        cin >> i;
    // vi a = {3, 10, 5, 15, 2};
    trie *root = buildTrie(a);
    int ans = helper(root, a);
    cout << ans;

    return 0;
}