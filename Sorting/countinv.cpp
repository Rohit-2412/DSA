#include <bits/stdc++.h>
using namespace std;
/*
we have to count the no. of inversion
an inversion means a set of two elements where 2nd element is smaller than 1st element like (5,1) , (6,3)......
this we can do by sorting the array using merge sort and counting the no. of inversion while doing sorting
*/

long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            //  a[i] > b[j]; inv case
            inv += n1 - i; // if one element of arr1 is greater than other element of arr2 it means rest elements will also be greater because it is a sorted array
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}
long long mergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}
int main()
{
    //     int n;
    //     cin >>n;
    //     int arr[n];
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin>>arr[i];
    //     }
    int arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204,
                 312, 323};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mergeSort(arr, 0, n - 1) << " ";

    return 0;
}
