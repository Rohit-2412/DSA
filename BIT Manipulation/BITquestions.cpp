#include <bits/stdc++.h>
using namespace std;
bool powerOf2(int n)
{
    return (n && !(n & n - 1)); // n && ........ for handling 0
}

int count1(int n)
{
    int count = 0;
    while (n)
    {
        n = (n & n - 1);
        count++;
    }
    return count++;
}

void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++) // loop goes to 2^n 
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) // this gives 0 1 2 3 4 5 6 7 8 .............
            {
                cout << arr[j] << " ";
            }
        }
            cout << endl;
    }
}
int main()
{
    // int n;
    // cin >> n;
    // check if a number is power of 2
    // cout << powerOf2(n) <<endl;

    // WAP to count number of ones in a binary number
    // cout << count1(n) << endl;

    // write all subsets of a set
    int arr[] = {1,2,3,4};
    subsets(arr,4);
    return 0;
}
