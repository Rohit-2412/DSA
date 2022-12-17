#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
// problem : you are given n files with thier computation times in array
// operation : choose/take any two files add their computation times and append it to the list of computation times.(cost = sum of computation time)

// approach : push the computation times in a min heap and add then add the value of top 2 files time and push it back to heap
// do this until you are left with one single file
int main()
{
    int n;
    cin >> n;
    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;

    rep(i, 0, n)
    {
        minHeap.push(a[i]);
    }

    int ans = 0;
    while (minHeap.size() > 1)
    {
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();

        ans += e1 + e2;
        minHeap.push(e1 + e2);
    }
    cout << ans << endl;
    return 0;
}