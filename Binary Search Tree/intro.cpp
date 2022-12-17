#include <bits/stdc++.h>
using namespace std;

// Binary Search Tree is a modified version of binary tree where 3 rules are followed :

// 1 left subtree should contain elements smaller than the root
// 2 right subtree should contain elements greater than the root
// 3 each subtree should also be a BST and there should be no repeated elements

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

Node *insertBST(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        // when val > root->data
        root->right = insertBST(root->right, val);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int arr[] = {5, 6, 7, 1, 9, 2, 8, 3, 4, 11, 16, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            root = insertBST(root, arr[i]);
            continue;
        }
        insertBST(root, arr[i]);
    }

    // printing inorder sequence of binary tree
    inorder(root);
    return 0;
}