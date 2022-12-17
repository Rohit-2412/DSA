#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}
int main()
{
    int n;
    cin >> n;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        rep(k, 0, n - 1 - i)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            value = fact(i) / (fact(j) * fact(i - j));
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
