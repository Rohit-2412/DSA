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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    // Heaps are the similar like Binary Tree
    // conditions are that : Root should be greater than all nodes -- this is called max Heap
    // or it should be smaller than all nodes -- this is called min Heap

    // how to create a heap using Array
    // at the start make the first element as a new Node then add second element in the left of Root
    // if we observe that the root is smaller than left node then we will swap their data (known as Heapify)
    // then we will add third element at the node>right position
    // if this position is also greater than root then we will again swap their data
    // and continue till so on...

    // Max heap example :
    Node *root1 = new Node(6);
    root1->left = new Node(5);
    root1->right = new Node(4);
    root1->left->left = new Node(1);
    root1->left->right = new Node(2);
    preorder(root1);
    cout << endl;

    // Min heap example :
    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->left = new Node(9);
    root2->left->right = new Node(8);
    preorder(root2);
    cout << endl;

    return 0;
}