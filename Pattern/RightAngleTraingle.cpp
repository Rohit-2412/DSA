#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 7, MOD = 1e9 + 7;
int main()
{
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // bottom
            if (i == n - 1)
                cout << "* ";
            // right line
            else if (j == n - 1)
                cout << "* ";
            // for diagonal / hypotenuse
            else if (j + i == n - 1)
                cout << "* ";
            // spaces
            else
                cout << "  ";
        }
        for (int j = 0; j < n; j++)
        {
            // bottom
            if (i == n - 1)
                cout << "* ";
            // left line
            else if (j == 0)
                cout << "* ";
            // for diagonal / hypotenuse
            else if (j == i)
                cout << "* ";
            // spaces
            else
                cout << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // bottom
            if (i == 0)
                cout << "* ";
            // right line
            else if (j == n - 1)
                cout << "* ";
            // for diagonal / hypotenuse
            else if (j == i)
                cout << "* ";
            // spaces
            else
                cout << "  ";
        }
        for (int j = 0; j < n; j++)
        {
            // top
            if (i == 0)
                cout << "* ";
            // left line
            else if (j == 0)
                cout << "* ";
            // for diagonal / hypotenuse
            else if (j + i == n - 1)
                cout << "* ";
            // spaces
            else
                cout << "  ";
        }
        cout << endl;
    }
    /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // top
                if (i == 0)
                    cout << "* ";
                // left line
                else if (j == 0)
                    cout << "* ";
                // for diagonal / hypotenuse
                else if (j + i == n - 1)
                    cout << "* ";
                // spaces
                else
                    cout << "  ";
            }
            cout << endl;
        }
    */
    /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // bottom
                if (i == n - 1)
                    cout << "* ";
                // left line
                else if (j == 0)
                    cout << "* ";
                // for diagonal / hypotenuse
                else if (j == i)
                    cout << "* ";
                // spaces
                else
                    cout << "  ";
            }
            cout << endl;
        }
        */

    return 0;
}