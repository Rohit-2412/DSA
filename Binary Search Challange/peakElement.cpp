#include <bits/stdc++.h>
using namespace std;

// Peak element : an element which is greater than its left and right element

// Strategy :

int findPeakElement(vector<int> v, int n, int low, int high)
{
    int mid = low + (high - low) / 2;

    // for mid element
    if ((mid == 0 || v[mid - 1] <= v[mid]) &&
        mid == n - 1 && v[mid + 1] <= v[mid])
    {
        return mid;
    }

    // for left half
    else if (mid > 0 && v[mid - 1] > v[mid])
    {
        return findPeakElement(v, n, low, mid - 1);
    }
    // for right half
    else
    {
        return findPeakElement(v, n, mid + 1, high);
    }
}
int main()
{
    vector<int> v;
    v = {0, 6, 8, 5, 7, 9};

    int n = v.size();

    cout << "Peak element idx : " << findPeakElement(v, n, 0, n - 1) << endl;

    return 0;
}