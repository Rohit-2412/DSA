#include <bits/stdc++.h>
using namespace std;
/*
given number of elements and a fixed sum
and we have to find three elements whose sum is equal to the given sum
*/
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    bool found = false;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int current = arr[i] + arr[low] + arr[high];
            if (current == target)
            {
                found = true;
                break;
            }
            else if (current < target)
                low++;
            else
                high--;
        }
    }
    if (found)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
