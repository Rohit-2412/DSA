#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int key, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[start] <= arr[mid])
    {
        if (key >= arr[start] && key <= arr[end])
        {
            // cal for left half
            search(arr, key, start, mid - 1);
        }
        // call for right half
        return search(arr, key, mid + 1, end);
    }

    if (key >= arr[mid] && key <= arr[end])
    {
        // call for right half
        return search(arr, key, mid + 1, end);
    }
    // call for left half
    return search(arr, key, start, mid - 1);
}

int main()
{
    // vector<int> v = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    vector<int> v = {5, 1, 3};
    int n = v.size();
    int key = 5;

    if (search(v, key, 0, n - 1) == -1)
    {
        cout << "Key does not exist" << endl;
    }
    else
    {
        cout << "Key is presnt at idx : " << search(v, key, 0, n - 1) << endl;
    }

    return 0;
}