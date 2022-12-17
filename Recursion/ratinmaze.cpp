#include <bits/stdc++.h>
using namespace std;
/*
in this problem we have to find the right path for a rat to go to its destination 
we will start from 0,0 and then first we move one step right and then one step down 

if we cant move any step then we will backtrack or u can say move to the last possible position and choose the other option out of two (down or left)
*/
bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}
bool ratinMaze(int **arr, int x, int y, int n, int **solnArr)
{
    if (x == n - 1 && y == n - 1)
    {
        solnArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solnArr[x][y] = 1;

        if (ratinMaze(arr, x + 1, y, n, solnArr))
        {
            return true;
        }
        if (ratinMaze(arr, x, y + 1, n, solnArr))
        {
            return true;
        }
        solnArr[x][y] = 0; // backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int **solnArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solnArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solnArr[i][j] = 0;
        }
    }
    if (ratinMaze(arr, 0, 0, n, solnArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solnArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    free(arr);
    return 0;
}
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/