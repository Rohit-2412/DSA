#include <bits/stdc++.h>
using namespace std;
// selection sort
// algorithm - select one element and place it at the beginning
// example -  1 (3) (2) 4
// 1st iteration 1 (2) (3) 4

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 1; i < n ; i++) // check from 2nd element to last
    {
        for (int j = 0; j < n-1; j++)   //compare it from 1st to 2nd-last element
        {
            if (array[j] > array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
} 
 