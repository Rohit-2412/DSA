#include <bits/stdc++.h>
using namespace std;
/* 
1. bruteforce 3 loops
2. prefix sum
3. kadane algorithm
*/
// bruteforce time = O(n^3)
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum <<endl;
    return 0;
}
