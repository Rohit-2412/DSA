#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem : you are given an array of n elements. you have to move n/2 elements of array A to B (initially empty)
// then find the maximum and min value of difference between these two arrays
// differcen is defined as ->> summation : abs(A[i] - B[i])
int main()
{
    int n;
    cin >> n;
    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long max = 0, min = 0;
    rep(i, 0, n / 2)
    {
        max += (a[n / 2 + i] - a[i]);

        min += a[2 * i + 1] - a[2 * i];
    }

    cout << "Maximum difference : " << max << endl;

    cout << "Minimum difference : " << min << endl;

    return 0;
}