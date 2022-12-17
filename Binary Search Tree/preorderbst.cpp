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

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{

    if (*preorderIdx >= n)
    {
        return NULL;
    }

    Node *root = NULL;
    if (key > min && key < max)
    {

        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {

            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        if (*preorderIdx < n)
        {

            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    printPreorder(root->left);
    printPreorder(root->right);
}
int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    int min = INT_MIN;
    int max = INT_MAX;

    Node *root = constructBST(preorder, &preorderIdx, preorder[0], min, max, n);
    printPreorder(root);
    return 0;
}