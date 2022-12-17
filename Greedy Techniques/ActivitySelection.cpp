#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem : you are given n activities with their start and finish times.
// Select the max. numbr of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

// Approach : sort the activities on the basis of their end times
// then select compare the end time of one process with start of second process... this will result in non overlapping activities whic is our answer.
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;

    rep(i, 0, n)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int take = 1;
    int end = v[0][1];
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] >= end)
        {
            take++;
            end = v[i][1];
        }
    }
    cout << take << endl;

    return 0;
}