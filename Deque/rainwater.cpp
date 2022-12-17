#include <bits/stdc++.h>
using namespace std;
int rain_water(vector<int> a)
{
    stack<int> st;
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[i] > a[st.top()])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> v;
    // v = {0, 1, 0, 2, 1, 10, 1, 3, 2, 1, 12, 1};
    v = {3, 0, 0, 2, 0, 4};
    cout << rain_water(v) << endl;

    return 0;
}
