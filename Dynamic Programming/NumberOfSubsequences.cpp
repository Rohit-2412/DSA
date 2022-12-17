#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// Problem :
// you are given an string of lowercase letters ('a' - 'z') ans some ?
// you have to tell the number of subsequences "abc" that can be formed by replacing ?  with  a or b or c

// Idea :
// maintain 4 varibales e a ab abc
// e denotes empty string
// a denotes count of subsequence "a" upto current element
// ab denotes count of subsequence "ab" upto current element
// abc denotes count of subsequence "abc" upto current element
int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int e = 1, a = 0, ab = 0, abc = 0;

    rep(i, 0, n)
    {
        if (s[i] == 'a')
            a += e;

        else if (s[i] == 'b')
            ab += a;

        else if (s[i] == 'c')
            abc += ab;

        if (s[i] == '?')
        {
            abc = 3 * abc + ab;
            ab = 3 * ab + a;
            a = 3 * a + e;
        }
    }

    cout << abc << endl;

    return 0;
}