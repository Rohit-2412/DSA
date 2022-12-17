#include <bits/stdc++.h>
using namespace std;
/*
given an array of 0's and 1's, return length of longest subarray that contains only 1's

we may change up to K values from 0 to 1
A={1, 1, 1, 1, 0, 0, 0, 0, 1, 1}
and k = 2
so w/o k maxLen = 4
with k = 2
it can become
1 1 1 1 1 1 0 0 1 1
maxLen = 6
*/
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    // a[i....j]
    // a[i...j+1] inc. win size
    // a[i+1....j] dec. win size

    int zerocnt = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
            zerocnt++;
        while (zerocnt > k)
        {
            if (a[i] == 0)
            {
                zerocnt--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    // zerocnt <=k
    cout << ans << endl;
    return 0;
}
