#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COLS 3
int main()
{
  int mtx[ROW][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // for (int i = 0; i < ROW; i++)
  // {
  //   for (int j = 0; j < COLS; j++)
  //   {
  //     cin >> mtx[i][j];
  //   }
  // }
// original matrix
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      cout << mtx[i][j] << " ";
    }
    cout << endl;
  }
  cout << "-----" <<  endl;

  // transposing
  for (int i = 0; i < ROW; i++)
  {
    for (int j = i; j < COLS; j++)
    {
      //swap elements
      int temp;
      temp = mtx[i][j];
      mtx[i][j] = mtx[j][i];
      mtx[j][i] = temp;
    }
  }
  // new mtx
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      cout << mtx[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
