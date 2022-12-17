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

// Approach one to compare at each node for its left and right subtree (this is wrong approach)

// Approach 2
// to compare the maximum value of left subtree and minimum value of right subtree with root value
// if root satisfies condition then it is BST otherwise not

bool checkBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    if (root == NULL)
        return true;

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftValid = checkBST(root->left, min, root);
    bool rightValid = checkBST(root->right, root, max);

    return leftValid && rightValid;
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    if (checkBST(root1, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Inavlid BST" << endl;
    }

    Node *root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(8);

    if (checkBST(root2, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Inavlid BST" << endl;
    }
    return 0;
}