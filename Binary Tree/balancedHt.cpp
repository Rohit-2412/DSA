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

int height(Node *root)
{

    if (root == NULL)
        return 0;
    int lHeight = height(root->right);
    int rHeight = height(root->left);
    return max(lHeight, rHeight) + 1;
}

bool isBalanced(Node *node)
{
    if (node == NULL)
        return true;

    if (isBalanced(node->left) == false)
    {
        return false;
    }
    if (isBalanced(node->right) == false)
    {
        return false;
    }

    int lh = height(node->left);
    int rh = height(node->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// more optimized version

bool isBal(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (isBal(root->left, &lh) == false)
        return false;
    if (isBal(root->right, &rh) == false)
        return false;

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    // Balanced hieght tree
    // the difference between heights of left subtree and heights of right subtree <= 1

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

    // if (isBalanced(root) == true)
    // {
    //     cout << "Balanced Tree" << endl;
    // }
    // else
    // {
    //     cout << "UnBalanced Tree" << endl;
    // }

    Node *root2 = new Node(1); // lvl 0
    root2->left = new Node(2); // lvl 1
    root2->left->left = new Node(3);

    // if (isBalanced(root2) == true)
    // {
    //     cout << "Balanced Tree" << endl;
    // }
    // else
    // {
    //     cout << "UnBalanced Tree" << endl;
    // }

    int height = 0;

    if (isBal(root, &height) == true)
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "UnBalanced Tree" << endl;
    }
    // ---- //
    if (isBal(root2, &height) == true)
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "UnBalanced Tree" << endl;
    }

    return 0;
}