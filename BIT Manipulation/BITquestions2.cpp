#include <bits/stdc++.h>
using namespace std;
int setBit(int n, int pos)
{
    return ((n | (1 << pos)));
}

bool getBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
int uniqueElement(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }

    return ans;
}
void unique(int arr[], int n) // for 2 element
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos - 1))
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << newxor << endl;
    cout << (newxor ^ tempxor) << endl;
}

int uniqueOf3(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setBit(result, i);
        }
    }
    return result;
}
int main()
{
    // WAP to find a unique element of an array where every element is present twice except one
    // int arr[] = {1,2,2,1,3,3,4};
    // cout << uniqueElement(arr,7) <<endl;
    // if we have two unique elements ....
    // int arr[] = {1, 2, 3, 4, 5, 6, 4, 3, 2, 1};
    // unique(arr, 10);
    int arr[] = {1, 1, 1, 2, 2, 2, 3};
    cout << uniqueOf3(arr, 7) << endl;
    ;
    return 0;
}
