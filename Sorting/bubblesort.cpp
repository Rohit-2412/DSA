#include <bits/stdc++.h>
using namespace std;
// bubble sort
// algorithm - find one element from left to right and place every element to its correct position (between two numbers)
int main()
{
    int n;
    cin >> n;
    // int array[100];
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // for increasing order
            if (array[i] < array[j])
                swap(array[i], array[j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // for decreasing order
            if (array[i] < array[j])
                swap(array[i], array[j]);
        }
    }
    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}