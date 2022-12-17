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

// SD = min nmuber of edges to be travelled to go from one node to another node

Node *LCA(Node *root, int n1, int n2)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{

    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return dist;
    }

    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }

    return findDist(root->right, k, dist + 1);
}

int distBtwNodes(Node *root, int n1, int n2)
{

    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(root, n1, 0);
    int d2 = findDist(root, n2, 0);

    return d1 + d2;
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
    root->left->left->left = new Node(8); // lvl 3
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    cout << distBtwNodes(root, 4, 5) << endl;

    return 0;
}