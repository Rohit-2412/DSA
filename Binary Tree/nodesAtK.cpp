#include <bits/stdc++.h>
using namespace std;
// Task : to print all the nodes at distance K from a node
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

// case 1 - when we have nodes in subtree only
void printSubtreeNodes(Node *root, int k)
{

    if (root == NULL || k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

// case 2 - when we have nodes in Ancestors also
// algorithm
// find the distance of all ancestors from target node
// for all the ancestors search other subtree nodes (K-d)
//
int printNodesAtK(Node *root, Node *target, int k)
{

    if (root == NULL)
        return -1;
    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, k);
    if (dl != -1)
    {

        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            // we call right because left->left is invalid position
            printSubtreeNodes(root->right, k - dl - 2); // -2 came because firstly we come one distance away to the ancestor and then we're calling for right subtree (which is again at distance 1) so total 1 + 1 = 2
        return 1 + dl;
    }

    int dr = printNodesAtK(root->left, target, k);
    if (dr != -1)
    {

        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            printSubtreeNodes(root->left, k - dr - 2); // -2 came because we're calling for nodes left part
        return dr + 1;
    }
    return -1;
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

    printNodesAtK(root, root->left, 1);
    return 0;
}