#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 7, MOD = 1e9 + 7;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int t;
    cin >> t;
    oset<int> s; // creating an int data type oset
    while (t--)
    {
        int c;
        cin >> c;

        if (c == 1)
        {
            int val;
            cin >> val;
            s.insert(val);
        }

        else if (c == 2)
        {
            int idx;
            cin >> idx;
            cout << *s.find_by_order(idx) << endl;
        }

        else
        {
            int t;
            cin >> t;
            cout << s.order_of_key(t) << endl;
        }
    }
    return 0;
}