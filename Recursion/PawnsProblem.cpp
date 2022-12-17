#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
vector<vector<char>> a(4, vector<char>(4, '.'));
int i = 1;

int random()
{
    srand(time(NULL));
    i++;
    return ((rand() / i)) % 4;
}

bool isSafe(int i, int j, string s)
{
    if (s == "up")
    {
        if (a[i - 1][j] == '.')
        {
            return true;
        }
    }
    if (s == "down")
    {
        if (a[i + 1][j] == '.')
        {
            return true;
        }
    }
    if (s == "left")
    {
        if (a[i][j - 1] == '.')
        {
            return true;
        }
    }
    if (s == "right")
    {
        if (a[i][j + 1] == '.')
        {
            return true;
        }
    }
    return false;
}
// cout << "(" << i << "," << j << ")<<endl;
int main()
{
    // rep(i, 0, 4)
    // {
    //     rep(j, 0, 4)
    //     {
    //         cin >> a[i][j];
    //     }
    // }
    int x, y;
    rep(i, 0, 5)
    {
        x = random();
        y = random();
        a[x][y] = 'X';
    }

    cout << "Possible indices are :" << endl;
    //  main program
    rep(i, 0, 4)
    {
        rep(j, 0, 4)
        {
            // Left corner
            if (i == 0 and j == 0 and a[i][j] == '.')
            {
                if (isSafe(i, j, "right") and isSafe(i, j, "down"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // right corner
            if (i == 0 and j == 3 and a[i][j] == '.')
            {
                if (isSafe(i, j, "left") and isSafe(i, j, "down"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // bottom left corner
            if (i == 3 and j == 0 and a[i][j] == '.')
            {
                if (isSafe(i, j, "right") and isSafe(i, j, "up"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // bottom right corner
            if (i == 3 and j == 3 and a[i][j] == '.')
            {
                if (isSafe(i, j, "right") and isSafe(i, j, "up"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // top horizontal line
            if (i == 0 and j != 0 and j != 3 and a[i][j] == '.')
            {
                if (isSafe(i, j, "left") and isSafe(i, j, "right") and isSafe(i, j, "down"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // bottom horizontal line
            if (i == 3 and j != 0 and j != 3 and a[i][j] == '.')
            {
                if (isSafe(i, j, "left") and isSafe(i, j, "right") and isSafe(i, j, "up"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // left vertical line
            if (j == 0 and i != 0 and i != 3 and a[i][j] == '.')
            {
                if (isSafe(i, j, "up") and isSafe(i, j, "down") and isSafe(i, j, "right"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // right vertical line
            if (j == 3 and i != 0 and i != 3 and a[i][j] == '.')
            {
                if (isSafe(i, j, "left") and isSafe(i, j, "down") and isSafe(i, j, "up"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
            // centre box
            if (i >= 1 and i <= 2 and j >= 1 and j <= 2)
            {
                if (isSafe(i, j, "up") and isSafe(i, j, "down") and isSafe(i, j, "left") and isSafe(i, j, "right"))
                {
                    cout << "(" << i << "," << j << ")" << endl;
                }
            }
        }
    }

    rep(i, 0, 4)
    {
        rep(j, 0, 4)
                cout
            << a[i][j] << " ";

        cout << endl;
    }

    return 0;
}
/*
. . . X
X . . x
. X X X
. . . .
*/