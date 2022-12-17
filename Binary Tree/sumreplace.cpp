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

// Replace all the nodes with the sum of their nodes and their data itself

void sumReplace(Node *root)
{
    if (root == NULL)
        return;
    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
}

void preoder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preoder(root->left);
    preoder(root->right);
}

int main()
{
    Node *root = new Node(1); // lvl 0
    root->left = new Node(2); // lvl 1
    root->right = new Node(3);
    root->left->left = new Node(4); // lvl 2
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // root->left->left->left = new Node(8); // lvl 3
    // root->left->left->right = new Node(9);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(11);

    preoder(root);
    cout << "\n";

    sumReplace(root);
    cout << "\n";

    preoder(root);
    cout << "\n";

    return 0;
}