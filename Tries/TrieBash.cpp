#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
/*
given an array find the maximum sum of xor of two subarrays of this given array

example :
4
1 2 6 8
1 xor 2 + 6 xor 8 = 3 + 14 = 17

idea:
  we will calculate the maximum XOR subaray at i and call it lmax
  then do the same procedure in reverse order of array and call it rmax

  then final ans = lmax[i] + rmax[i+1]
*/

class node
{
public:
	node *next[2];
	node()
	{
		rep(i, 0, 2)
			next[i] = NULL;
	}
};

node *trie;
int int_size = 32;
void insert(int num)
{
	node *it = trie;
	for (int i = int_size - 1; i >= 0; i--)
	{
		int cur_bit = (num >> i) & 1;
		if (!it->next[cur_bit])
			it->next[cur_bit] = new node();
		it = it->next[cur_bit];
	}
}

int query(int num)
{
	node *it = trie;
	int ans = 0;

	for (int i = int_size - 1; i >= 0; i--)
	{
		int cur_bit = (num >> i) & 1;
		int opposite_bit = cur_bit xor 1;

		if (it->next[opposite_bit])
		{
			it = it->next[opposite_bit];
			ans |= 1 << i;
		}

		else
		{
			it = it->next[opposite_bit xor 1];
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vi a(n);

	for (auto &i : a)
		cin >> i;

	trie = new node();
	insert(0);

	vi rmax(n + 1, 0);
	int R = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		R = R xor a[i];
		if (i != n - 1)
		{
			rmax[i] = max(rmax[i], query(R));
			insert(R);
		}
		else
		{
			rmax[i] = query(R);
			insert(R);
		}
	}

	free(trie);
	trie = new node();
	insert(0);
	int ans = 0;
	int L = 0;
	for (int i = 0; i < n; i++)
	{
		L = L xor a[i];
		ans = max(ans, rmax[i + 1] + query(L));
		insert(L);
	}
	cout << ans;
	return 0;
}