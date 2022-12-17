#include <bits/stdc++.h>
using namespace std;
// circular array means which can be started again from last element
/* example 1 2 -2 -3 3 4 
maxsum = 7 for simple array
maxsum = 8 (3 4 1) for cicular array

we will find contributing and non contributing element 
ans will be ({{contributing sum - non contribuitng sum}})
*/
int kadane(int arr[], int n)
{
  int currentSum = 0;
  int maxSum = 0;
  for (int i = 0; i < n; i++)
  {
    currentSum += arr[i];
    if (currentSum < 1)
    {
      currentSum = 0;
    }
    maxSum = max(currentSum, maxSum);
  }
  return maxSum;
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int wrapSum;
  int nonwrapSum;
  nonwrapSum = kadane(arr, n); //finding max sum for simple array
  int totalsum = 0;            // ans variable
  // changing sign of each element
  for (int i = 0; i < n; i++)
  {
    totalsum += arr[i]; // calculating total sum of all elements
    arr[i] = -arr[i];   // change of sign
  }
  wrapSum = totalsum + kadane(arr, n);
  cout << wrapSum << endl;
  return 0;
}
