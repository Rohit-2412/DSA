#include <bits/stdc++.h>
using namespace std;
//insertion sort
// algorithm - find one element from left to right and place every element to its correct position (between two numbers)
int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 1; i < n; i++)
    {
        int current = array[i];
        int j = i - 1;
        while (array[j] > current && j >= 0) // checking for greater elements
        {
            array[j + 1] = array[j]; //shifting rest elements
            j--;                     //decrementing by one so that it check again for element prev to current moved element
        }
        array[j + 1] = current; // placing smaller element to its position      //we put j+1 becuase when this loop breaks j decreases by 1
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
