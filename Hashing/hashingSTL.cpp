#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
    // we have
    //               map     and    unordered_map
    // insertion : O(log n)         O(1)
    // accessing : O(log n)         O(1)
    // deletio n : O(log n)          O(n)
    // implementation :Red - Black Tree Hash tables
    //                 key value pairs
    // map<int,int> mp;     unordered_map<int,int> mp;

    map<int, int> m;

    m[8] = 2;
    cout << m[8] << endl;
    return 0;
}