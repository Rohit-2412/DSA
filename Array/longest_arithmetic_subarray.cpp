#include <bits/stdc++.h>
using namespace std;
/* conditon is that an array contains at leat 2 elements and the diff. b/w two consecutive integers are equal
eg. 9 10
    9 7 5 3
    1 3 3 7(not an arithmetic subarray)
    output will be length of that subarray (min. ans= 2)
*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 2;
    int j = 2;
    int d = arr[1] - arr[0];
    int curr = 2;
    while (j < n)
    {
        if (arr[j] - arr[j - 1] == d)
        {
            curr++;
        }
        else
        {
            d = arr[j] - arr[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    cout << ans << endl;
    return 0;
}
