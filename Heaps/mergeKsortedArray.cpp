#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
    int k;
    cout << "Enter number of Arrays : ";
    cin >> k;

    vector<vector<int>> a(k); // 2d vector

    rep(i, 0, k)
    {
        int size;
        cout << "Enter size of array : ";
        cin >> size;

        a[i] = vector<int>(size);
        rep(j, 0, size)
        {
            cout << "Enter elements of array : ";
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);

    // step 1:
    // min heap of pair of int and int
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    rep(i, 0, k)
    {
        // Step 2:
        // insert first element of each array
        // {first element, array number}
        pq.push({a[i][0], i});
    }

    // Step 3: we will pop element from min heap and store into the answer vector. insert the next element of the sorted array into the min heap
    // we also need to keep track of the indices of the

    vi ans; // ans vector

    while (!pq.empty())
    {
        // top element of min heap will be the smallest value of all
        // so we will access the top element of current min heap (smallest element of first values of all array)
        // then we will pop the top element

        // making pair of int & int
        pii temp = pq.top(); // storing top element
        pq.pop();            // popping it

        ans.push_back(temp.ff); // adding top element to the ans vector

        if (idx[temp.ss] + 1 < a[temp.ss].size()) // checking if next idx of current array is possible to access
        {
            // if yes, then
            // push ([current_array_number][next_element] , array_number)
            pq.push({a[temp.ss][idx[temp.ss] + 1], temp.ss});
        }
        // incrementing array count
        idx[temp.ss] += 1;
    }

    // printing ans vector
    rep(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}