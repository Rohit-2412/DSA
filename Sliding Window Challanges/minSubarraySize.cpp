#include <bits/stdc++.h>
using namespace std;

int smallestSubarrayWithSum(vector<int> arr, int n, int x)
{
    int sum = 0, minLength = n + 1, start = 0, end = 0;

    while (end < n)
    {
        while (sum <= x and end < n)
        {
            sum += arr[end++];
        }

        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}

int main()
{
    vector<int> arr;
    arr = {1, 4, 45, 6, 10, 19};
    int n = arr.size();
    int x = 50;

    int minLength = smallestSubarrayWithSum(arr, n, x);
    if (minLength > n)
    {
        cout << "No such subarray exists" << endl;
    }
    else
    {
        cout << "Smallest length subarray is : " << minLength << endl;
    }

    return 0;
}