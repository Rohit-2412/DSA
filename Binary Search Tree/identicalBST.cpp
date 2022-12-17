#include <bits/stdc++.h>
using namespace std;
// IdenticalBst are the trees when they are identically same and also have same values

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

// Strategy
// check if both are empty -> then true
// check if both have left subtree
// check if both have right subtree

// check if value at node and left subtree and right subtree are equal

// if any condition is false then return FALSE

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool condition1 = root1->data == root2->data;

        bool condition2 = isIdentical(root1->left, root2->left);

        bool condition3 = isIdentical(root1->right, root2->right);

        if (condition1 && condition2 && condition3 == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    if (isIdentical(root1, root1))
    {
        cout << "Identical BSTs" << endl;
    }

    else
    {
        cout << "BSTs are Not Identical" << endl;
    }

    Node *root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(0);
    // root2->right = new Node(3);

    if (isIdentical(root1, root2))
    {
        cout << "Identical BSTs" << endl;
    }

    else
    {
        cout << "BSTs are Not Identical" << endl;
    }

    return 0;
}