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

Node *searchInBST(Node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }

    return searchInBST(root->right, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            root = new Node(arr[i]);
            continue;
        }
        insertBST(root, arr[i]);
    }
    // searching val in BT
    if (searchInBST(root, 5) == NULL)
    {
        cout << "Key doesn't exist" << endl;
    }
    else
    {
        cout << "Key exists" << endl;
    }
    return 0;
}