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

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int main()
{
    Node *root = new Node(1); // lvl 0
    root->left = new Node(2); // lvl 1
    root->right = new Node(3);
    root->left->left = new Node(4); // lvl 2
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->left->right = new Node(7);
    root->left->left->left = new Node(8); // lvl 3
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    // Count the number of nodes in a Binary Tree
    // cout << countNodes(root) << endl;

    // Sum of all nodes in a Binary Tree
    // cout << sumNodes(root) << endl;

    return 0;
}