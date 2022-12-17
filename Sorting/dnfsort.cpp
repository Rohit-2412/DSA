#include <bits/stdc++.h>
using namespace std;
/*
dnf sort is used to sort an array consisting of only three elements like 0 1 2
we will make three areas low mid high
we'll start comparing from mid=0 and if at high pos(i.e, n-1) is 2 then decrease high by one pos. and swap mid and high values
if high == 1 then leave it there
if high == 0 then swap it mid and low values
*/

// void swap(int arr[], int i, int j)
// {
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }
void dnfSort(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // swap(arr, low, mid);
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else // arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    int arr[] = {1, 0, 1, 1, 1, 1, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    dnfSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
