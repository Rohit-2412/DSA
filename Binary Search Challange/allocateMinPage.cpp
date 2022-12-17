#include <bits/stdc++.h>
using namespace std;

// Problem : n - number of pages in diff. books (asc order)
// m - number of students
// All the books have to be divided among m students, consecutively. Allocate the pages in such a way that maximum pages allocated to a student is minimum.

// example :
// [12, 34, 67, 90]
// m = 2
// possible allocations : [12] , [34, 67, 90] { 191 }
// [12, 34] , [67,90] {157}
// [12, 34,67] , [90] {113} {{max possible minimum}}

// strategy :
// apply binary search for max and min possible values of 'max' pages
// check feasibility of this value
// for Feasibility :
// assign pages to each student in a sequential manner, while the current number of allocated pages don't exceed the value by binary search

// if during allocation the number of students don't exceed the limit of 'm' , then the soln is feasible else, it isn't

bool isPossible(vector<int> arr, int n, int m, int min)
{
    int studentRequired = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }

        if (sum + arr[i] > min)
        {
            studentRequired++;
            sum = arr[i];
        }

        if (studentRequired > m)
        {
            return false;
        }

        else
        {
            sum += arr[i];
        }
    }

    return true;
}

int allocateMinPage(vector<int> arr, int n, int m)
{
    int sum = 0;
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // binary search conditions

    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {

        int mid = (start + end) / 2;
        // first possible case
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1; // if we got one solution then checking the right half for one more solution better than current
        }
        // if we got no solution in left half then checking in the right half
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    // int arr[] = {12, 34, 67, 90};
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    int m = 2;
    // we need maximum number of books with minimum sum
    cout << "The minimum number of pages : " << allocateMinPage(arr, n, m) << endl;

    return 0;
}