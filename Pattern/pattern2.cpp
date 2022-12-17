#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pattern

    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

    // int n;
    // cin >> n;

    // for (int i = 1; i <=n; i++)
    // {
    //     for (int j = 1; j <=n+1-i; j++)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // 0 - 1 pattern

    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         /* code */
    //         if ((i + j) % 2 == 0)
    //         {
    //             cout << "1 ";
    //         }
    //         else
    //         {
    //             cout << "0 ";
    //         }
    //     }cout<<endl;
    // }

    // rhombus pattern

    //      * * * * *
    //     * * * * *
    //    * * * * *
    //   * * * * *
    // * * * * *

    // n = 6
    //             * * * * * *
    //          * * * * * *
    //        * * * * * *
    //      * * * * * *
    //    * * * * * *
    //  * * * * * *

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << " *";
    //     }
    //     cout << endl;
    // }

    //     1
    //    1 2
    //   1 2 3
    //  1 2 3 4
    // 1 2 3 4 5

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= i; j++)
    //     {
    //         /* code */
    //         cout << j <<" " ;
    //     }
    //     cout << endl;
    // }

    // palindromic pattern
    //         1
    //       2 1 2
    //     3 2 1 2 3
    //   4 3 2 1 2 3 4
    // 5 4 3 2 1 2 3 4 5

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     int j = 0;
    //     for (j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     int k = i;
    //     for (; j <= n; j++)
    //     {
    //         cout << k--<<" ";
    //     }
    //     k = 2;
    //     for (; j <= n + i - 1; j++)
    //     {
    //         cout << k++<<" ";
    //     }
    //     cout << endl;
    // }

    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *
    // * * * * * * * * *
    //   * * * * * * *
    //     * * * * *
    //       * * *
    //         *

    // int n;
    // cin >> n;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int j = 1; j <= (2 * i) - 1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // for (int i = n; i >= 0; i--)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int j = 1; j <= (2 * i) - 1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // zig zag pattern
    //         *         *
    //   *     *   *     *
    // *         *         *

    // int n;
    // cin >> n;
    // for (int i = 1; i <= 3; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (((i + j) % 4 == 0))
    //         {
    //             cout << "* ";
    //         }
    //         if (i == 2 && ((j % 4) == 0))
    //         {
    //             cout << "* ";
    //         }
    //         else
    //             cout << "  ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
