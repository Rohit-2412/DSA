#include <iostream>
using namespace std;
// to find nCr using function
int factorial(int num)
{
  int fact = 1;
  for (int i = 1; i <= num; i++)
  {
    fact *= i;
  }
  return fact;
}
int main()
{
  int n, r;
  cout << "enter n : ";
  cin >> n;
  cout << "enter r : ";
  cin >> r;
  int nCr = factorial(n) / (factorial(r) * factorial(n - r));
  // int fact=factorial(5);
  
  // cout << fact << endl;
  cout << nCr << endl;

  return 0;
}
