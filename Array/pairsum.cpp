#include <bits/stdc++.h>
using namespace std;
//task is to find two elements whose sum is equal to the given sum
// for array 1 2 3 10 23 and sum = 13

// print index of both element i.e. 2 3

// for optimized approach we need to sort the array and apply this technique
// first we will add the first and last element and if our sum is less we will increment start index ............. if sum is greter then we will decrement the end index ........... and we will find our desired sum

bool pairSum(int arr[], int n, int s)
{
  int low = 0, high = n - 1;
  while (low < high)
  {
    if (arr[low] + arr[high] == s)
    {
      cout << low << " " << high << endl;
      return true;
    }
    else if (arr[low] + arr[high] > s)
    {
      high--;
    }

    else
    {
      low++;
    }
  }
  return false;
}
int main()
{
  int n, sum;
  cin >> n >> sum;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // pairSum(arr, n, sum);
  cout << pairSum(arr, n, sum) << endl;
  // cout << arr[3]+arr[2] << endl;
  return 0;
}
