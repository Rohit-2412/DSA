#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Maximum subarray sum
// maintain two ptr
// one is curr it stores the value of each element of array one by one
// second is MaxTillNow it stores the max value of sum of all previous elements
int main()
{
    int n;
    cin >> n;

    vi a(n);

    rep(i, 0, n)
            cin >>
        a[i];

    int curr = 0, maxTillNow = 0;

    rep(i, 0, n)
    {
        curr += a[i];

        maxTillNow = max(maxTillNow, curr);

        if (curr < 0)
            curr = 0;
    }
    cout << maxTillNow << endl;
    return 0;
}