#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, value;
    n = 5;
    cin >> value;
    int arr[5][5] = {1, 2, 7, 11, 15, 2, 5, 8, 12, 19, 3, 6, 9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30};
    bool found = false;
    int r = 0, c = n - 1;
    while (r < n && c >= 0)
    {
        if (arr[r][c] == value)
        {
            found = true;
            break;
        }
        arr[r][c] > value ? (c--) : (r++);
    }
    found == true ? (cout << "Element found" << endl) : (cout << "Element not found" << endl);
    cout << r << " " << c;
    return 0;
}
