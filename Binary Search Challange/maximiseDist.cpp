#include <bits/stdc++.h>
using namespace std;
// Problem - to place K elements in a array of N size such that the minimum difference between two adjacent elements is maximum

bool isFeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;

            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1, right = arr[n - 1];

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }

        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {2, 4, 8, 9, 1};
    int n = 5;
    int k = 3;

    cout << "Largest distance: " << largestMinDistance(arr, 5, 3) << endl;
    return 0;
}