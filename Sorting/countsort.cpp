#include <bits/stdc++.h>
using namespace std;
/*
process of this sorting technique - 
first get the max element of the array
and create a array of that size
after this count the frequency of each element and place its value at num's index like if freq for '3' = 5 then arr[3]=5
after freq array
update each position's value by sum of all prev value 
freq arr=    0 1 4 5 2
updated arr= 0 1 5 10 12
now traverse the array from end and place the values accordingly 
*/
void countSort(int arr[], int n)
{
  int k = arr[0];
  for (int i = 0; i < n; i++)
  {
    k = max(k, arr[i]);
  }
  int count[k+1] = {0};
  for (int i = 0; i < n; i++)
  {
    count[arr[i]]++;
  }
  for (int i = 1; i <= k; i++)
  {
    /* code */
    count[i] += count[i - 1];
  }
  int output[n];
  for (int i = n - 1; i >= 0; i--)
  {
    output[--count[arr[i]]] = arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    arr[i] = output[i];
  }
}
int main()
{
  int arr[] = {1,3,2,3,4,1,6,4,3};
  int n = sizeof(arr) / sizeof(arr[0]);
  countSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}
