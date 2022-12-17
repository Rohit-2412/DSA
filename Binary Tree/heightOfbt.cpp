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

int calcHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcDiameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

int calcDia(Node *root, int *height)
{

    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calcDia(root->left, &lh);
    int rDiameter = calcDia(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
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
    // root->left->left->left = new Node(8); // lvl 3
    // root->left->left->right = new Node(9);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(11);

    // to calculate of height of a binary tree
    // cout << calcHeight(root) << endl;

    // to calculate diameter of a binary tree
    // Diameter - longest path b/w two nodes (can be through root or not through root)
    // cout << calcDiameter(root) << endl;

    // more optimized code order O(n)
    int height = 0;
    cout << calcDia(root, &height) << "\n";

    return 0;
}