#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

// To sort an array using heaps concept:
// firstly we will make a binary tree using the array
// then we will access the tree elements from last position (2*i +1 :: left & 2*i+2 :: right)
// then we will compare this element with the root->value if root-> value < leaf-> value then we will swap their positions and pop the root value
// and continue this till we have sorted the whole array

// example : [10, 15, 21, 30, 18, 19]
// BT :
//      10
//     /  \
//    15   21
//   /  \    \
//  30  18   19

// maxHEAP:
/*
      30
     / \
    18  21
    / \  \
    15 10 19
*/
// array representation : [30 18 21 15 10 19]
// we will comapre the last element of the BT with root value and then swap their positions and pop root value from BT
// then go to next element (here 10) compare it with root and then swap their positions then pop root from BT.

// (vector, idx from where we need to start, idx till where we need to do this)
void heapify(vi &a, int n, int i)
{
    int maxIdx = i;           // from where to start
    int leftIdx = 2 * i + 1;  // left idx
    int rightIdx = 2 * i + 2; // right idx

    if (leftIdx < n && a[leftIdx] > a[maxIdx]) // if leftIdx is valid and value at leftIdx is > than maxIdx value
    // then update maxIdx with l
    {
        maxIdx = leftIdx;
    }

    if (rightIdx < n && a[rightIdx] > a[maxIdx]) // if rightIdx is valid and value at right idx > value at maxIdx
    // then update maxIdx with r
    {
        maxIdx = rightIdx;
    }

    if (maxIdx != i) // if maxIdx is having value other than i(maxIdx) then swap values
    {
        swap(a[i], a[maxIdx]);

        heapify(a, n, maxIdx);
    }
}

void heapsort(vi &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
        // (vector, size, index) idx till where we want to heapify
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        // swaping first with last element

        heapify(a, i, 0);
        // (vector, idx from where heapify needs to be started, starting idx)
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vi a(n);
    cout << "Enter elements : ";
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    heapsort(a);

    rep(i, 0, n)
    {
        cout << a[i] << " ";
    }
    // for (auto i : a)
    // {
    //     cout << i << " ";
    // }
    cout << endl;
    return 0;
}