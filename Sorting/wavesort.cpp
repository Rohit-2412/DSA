#include <bits/stdc++.h>
using namespace std;
// we have to sort our array in this manner such that ---
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ...........
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void waveSort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        /* code */
        if (arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        if (arr[i] > arr[i + 1] && i <= (n - 2))
        {
            swap(arr, i, i + 1);
        }
    }
}
int main()
{
    int arr[] = {1, 3,4,7,5,6,2,0,9,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    waveSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
