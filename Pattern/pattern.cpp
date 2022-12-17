#include <bits/stdc++.h>
using namespace std;

int main()
{
    // rectangle pattern

    // * * * *
    // * * * *
    // * * * *
    // * * * *
    // * * * *

    // i = rows
    // j = columns

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout <<"* " ;
    //     }
    //     cout<<endl;
    // }

    // hollow rectangle

    // * * * * *
    // *       *
    // *       *
    // *       *
    // * * * * *

    // int rows;
    // int cols;
    // cin >> rows >> cols;
    // for (int i = 1; i <= rows; i++)
    // {
    //     for (int j = 1; j <= cols; j++)
    //     {
    //         if (j == 1 || j == cols || i == 1 || i == rows)
    //         {
    //             cout << "* ";
    //         }
    //         // else if (j == 0 || j == cols)
    //         // {
    //         //     cout << "* ";
    //         // }
    //         else
    //             cout << "  ";
    //     }
    //     cout << endl;
    // }

    // inverted half pyramid

    // * * * * *
    // * * * *
    // * * *
    // * *
    // *

    // int n;
    // cin >> n;
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         /* code */
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // inverted pyramid after 180 deg rotation

    //       *
    //     * *
    //   * * *
    // * * * *
    // * * * *

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         if (j <= (n - i))
    //         {
    //             cout << "  ";
    //         }
    //         else
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     cout << endl;
    // }

    // half pyramid using numbers

    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // flyod's triangle

    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15

    // int n;
    // cin >> n;
    // int k = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         // cout.width(2); // to print the output in 2 width
    //         cout << k << " ";
    //         k++;
    //     }
    //     cout << endl;
    // }

    // butterfly pattern

    // for n = 4
    // *             *
    // * *         * *
    // * * *     * * *
    // * * * * * * * *
    // * * * * * * * *
    // * * *     * * *
    // * *         * *

    int n;
    cin >> n;
    // upper part
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    // lower part
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
