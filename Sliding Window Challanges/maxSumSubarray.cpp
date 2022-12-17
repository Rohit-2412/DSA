#include <bits/stdc++.h>
using namespace std;

void maxSumSubarray(vector<int> arr, int n, int k, int x)
{
    int sum = 0, ans = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    if (sum < x)
    {
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k];
        sum = sum + arr[i];

        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }
    cout << ans << " is the max subarray sum less than " << x << endl;
}

int main()
{
    vector<int> arr = {7, 5, 4, 6, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = arr.size();
    int k = 3;
    int x = 25;

    maxSumSubarray(arr, n, k, x);

    return 0;
}