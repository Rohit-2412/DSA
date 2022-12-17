#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x)
{
    // if both heaps are of equal size
    if (pqmax.size() == pqmin.size())
    {
        // if they're empty
        if (pqmin.size() == 0)
        {
            // push into max heap
            pqmax.push(x);
            return;
        }

        // if new element is smaller than top of maxHeap then insert it in max heap
        if (x < pqmax.top())
        {
            pqmax.push(x);
        }
        // if new element is greater than top of maxHeap then insert it in min heap
        else
        {
            pqmin.push(x);
        }
    }

    // if size is unequal
    else
    {
        // two cases possible :
        // Case 1: size of maxHeap > size of minHeap
        // Case 2: size of minHeap > size of maxHeap

        if (pqmax.size() > pqmin.size())
        {
            if (x >= pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }

        else
        {
            if (x <= pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }

    else if (pqmax.size() > pqmin.size())
    {
        return (pqmax.top());
    }

    else
    {
        return (pqmin.top());
    }
}
int main()
{
    // insert(10);
    // cout << findMedian() << endl;

    // insert(15);
    // cout << findMedian() << endl;

    // insert(21);
    // cout << findMedian() << endl;

    // insert(30);
    // cout << findMedian() << endl;

    // insert(18);
    // cout << findMedian() << endl;

    // insert(19);
    // cout << findMedian() << endl;

    vi v;
    v = {1, 3, 5, 7, 9, 11, 13, 2, 4, 6, 8};

    for (int i = 0; i < v.size(); i++)
    {
        insert(v[i]);
        cout << findMedian() << " ";
    }
    return 0;
}