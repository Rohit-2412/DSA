#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);

    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void preorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    Node *root = sortedArrayToBST(arr, 0, n - 1);

    preorderPrint(root);
    cout << endl;

    return 0;
}