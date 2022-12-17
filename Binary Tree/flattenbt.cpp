#include <bits/stdc++.h>
using namespace std;

// given a binary tree flatten it into linked list in place. after flattening left of each node should point to null and right of each node should conatain next node in preorder sequence (You can't use another data structure)

// ALgorithm
// 1 recursively flatten the left and right subtree
// 2 store the left and right tail
// 3 store right subtree in "temp" and make left subtree as right subtree
// 4 join right subtree with left tail
// 5 return right tail

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

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {

        flatten(root->left); // Recursive call for flattening left subtree

        Node *temp = root->right; // storing right subtree in temp
        root->right = root->left; // making left as right subtree
        root->left = NULL;        // make the left subtree as NULL becoz its empty now

        Node *t = root->right; // storing right subtree in a varible
        while (t->right != NULL)
        {
            t = t->right; // adding right subtree elements after left subtree elements
        }

        t->right = temp; // adding tail of right subtree to the end of the flatten tree
    }

    flatten(root->right);
}

void inorderPrint(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
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
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    flatten(root);
    inorderPrint(root);
    return 0;
}