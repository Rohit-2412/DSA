#include <bits/stdc++.h>
using namespace std;
// we have to return the start and end index of a subarray whose sum is equal to given sum
// given array is sorted    
// example sum= 50
// array = 10 20 30 45
// output = 2 3 (positions)

int main()
{
    int n, targetSum;
    cin >> n >> targetSum;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = 0;
    int st = -1, end = -1;
    int sum = 0;
    while (j < n && sum + a[j] <= targetSum)
    {
        sum += a[j];
        j++;
    }
    if (sum == targetSum)
    {
        cout << i + 1 << " " << endl;
    }
    while (j < n)
    {
        sum += a[j];
        while (sum > targetSum)
        {
            sum -= a[i];
            i++;
        }
        if (sum == targetSum)
        {
            st = i + 1;
            end = j + 1;
            break;
        }
        j++;
    }
    cout << st << " " << end << endl;

    return 0;
}
