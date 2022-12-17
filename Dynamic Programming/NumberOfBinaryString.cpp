#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
/*
Count the number of binary strings w.o consecutive 1's
for n = 3;
we have
000 001 101 010 100 (total 5)
*/

/*
Idea:
base case:
n = 1
2 strings 0 or 1

Recurrence relation:
    possible strings
    XX...10
    XX...01 + XX...10

at length i
we have one[1..i-1] , zero[1..i-1]
one[i] = zero[i-1]
zero[i] = one[i-1] + zero[i-1]

from obseravtion :
one[i-1] = zero[i-2] --- eq 1
zero[i] = one[i-1] + zero[i-1]
        = zero[i-2] + zero[i-1] (from eq 1)

Final Ans : zero[i] + one[i]
            zero[i] + zero[i-1]
            zeero[i+1]
            Fibonacci[n+1]

*/

int main()
{
    int n;
    cin >> n;

    vi dp(n + 2,0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n + 1;i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n+1];

    return 0;
}
/*
1 1
2 3
3 5
4 9
5 13
6 21
7 34
8 55
9 89

*/