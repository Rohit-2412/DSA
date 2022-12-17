#include <bits/stdc++.h>
using namespace std;
// permutation of string
void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);

        permutation(ros, ans + ch);
    }
}
// no. of possible steps from start to end point
int counthPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += counthPath(s + i, e);
    }
    return count;
}
// no. of path in n *n maze
int countPathMaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    return countPathMaze(n, i + 1, j) + countPathMaze(n, i, j + 1);
}
int main()
{
    // permutation("123", "");
    // cout << counthPath(0,3)<<endl;
    // cout << countPathMaze(8, 0, 0) << endl;
    return 0;
}
