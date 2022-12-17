#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        int l, p; // l = dist of town from initial point // p = initial fuel
        cin >> l >> p;

        for (int i = 0; i < n; i++)
        {
            // calculating distance of all stops from initial point
            a[i].first = l - a[i].first;
        }

        sort(a.begin(), a.end());

        int ans = 0;  // no. of stops taken
        int curr = p; // current fuel

        priority_queue<int, vector<int>> pq;
        bool flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (curr >= l)
                break;

            while (curr < a[i].first)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }

            if (flag)
                break;

            pq.push(a[i].second); // adding fuel to the heap
        }

        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }

        while (!pq.empty() && curr < l)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
/*
test case :
1
4
4 4
5 2
11 5
15 10
25 10
*/