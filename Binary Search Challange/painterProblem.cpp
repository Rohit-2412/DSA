#include <bits/stdc++.h>
using namespace std;

int findFeasible(int boards[], int n, int limit)
{
    int sum = 0, painters = 1;

    for (int i = 0; i < n; i++)
    {
        sum += boards[i];

        if (sum > limit)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[], int n, int m)
{
    int totalLength = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int low = k, high = totalLength;

    while (low < high)
    {
        int mid = (high + low) / 2;
        int painters = findFeasible(boards, n, mid);

        if (painters <= m)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int arr[] = {15, 20, 30, 40, 45};
    int n = 5;
    int m = 2;

    cout << "The minimum time to paint all the boards is : " << paintersPartition(arr, n, m) << endl;

    return 0;
}