#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 2, MOD = 1e9 + 7;

int main()
{
    string s1 = "na";
    string s2 = "apna banana";

    int size1 = s1.size();
    int size2 = s2.size();

    // substr function
    // string{where we want to search}.substr(index from where to start searching , size of sub-string to search)

    for (int i = 0; i < size2 - size1 + 1; i++)
    {
        if (s2.substr(i, size1) == s1)
            cout << "Found at index " << i << endl;
    }

    return 0;
}