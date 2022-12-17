#include <bits/stdc++.h>
using namespace std;
/* 
sub array is a part of array and also contiguous
eg 1 2 3 4 5
subarray = 1 , 1 2 ,1 2 3,1 2 3 4 , 1 2 3 4 5
2, 2 3 4 5, ..........and so on  

SUB SEQUENCE - it is all possible permutations of an array
example 1 2 2
subsequence = 
            {}
            {1}
            {2}
            {2}
            {1 2}
            {1 2}
            {2 2}
            {1 2 2}


*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cout << sum << endl;
        }
    }

    return 0;
}
