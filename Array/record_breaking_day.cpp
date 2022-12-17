#include <bits/stdc++.h>
using namespace std;
/*

record breakin day means -
no. of visitor of current day need to be greater than all prev days
either it is last day or no. of visitor is larger than the following day
example -
1 2 0 7 2 0 2 2
N Y N Y N N N N

output will be no. of record breaking days
*/
int main()
{
    int n;
    cin >> n;
    int a[100 + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = -1;
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx && a[i] > 0)
        {
            ans++;
            mx = max(mx, a[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
