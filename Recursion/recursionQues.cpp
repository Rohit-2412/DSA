#include <bits/stdc++.h>
using namespace std;
// to check array is sorted using recursion
bool sorted(int arr[], int n)
{
    if (n == 1) // base case if arr has only one element then it must be sorted
    {
        return true;
    }
    bool restArray = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restArray);
}
// print n numbers
// decreasing and increasing
void dec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    dec(n - 1);
}
void inc(int n)
{
    if (n == 0)
    {
        return;
    }
    inc(n - 1);
    cout << n << " ";
}
// first and last occurence of a number in an array
// first occurence
int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return (firstocc(arr, n, i + 1, key));
}
int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = lastocc(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6,7};
    // cout <<sorted(arr,7) << endl;
    // int n;
    // cin >> n;
    // dec(n);
    // inc(n);
    int arr[] = {1, 2, 3, 4, 2, 1, 2, 4};
    // cout << firstocc(arr, 8, 0, 2) << endl;
    // cout << lastocc(arr, 8, 0, 2) << endl;
    return 0;
}
