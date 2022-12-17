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
// Case 1 :
// when wrong elements are not adajcent to each other
// for this we will use 3 pointers -> first, mid, last
// first : prev node where 1st time BST rule is violated
// mid : number where 1st number < prev number (ideally it should be greater than prev number for a BST)
// last : 2nd node where number < prev (ideally it should be greater than prev number)

// Case 2:
// when wrong elements are adajcent to each other
// for this case also we will use three pointers and value remains the same
// in this case third pointer "last" will be NULL because rule will be violated only once

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calcPointers(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }

        else
        {
            *last = root;
        }
    }

    *prev = root;

    calcPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node *root)
{
    Node *first, *mid, *last, *prev;
    // here prev will act as an temp variable

    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    // case 1
    // for case 1 first and last pointers(node ptr) will not be null
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }

    // case 2
    // for case 2 first and mid pointers will not be null and third will be NULL
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    /*
                6
               /  \
              9    3
             / \    \
             1 4    13
    */
    // case 1
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);
    cout << "\n";

    restoreBST(root);

    inorder(root);
    cout << "\n";

    cout << "---------------------" << endl;

    // // case 2
    // /*
    //             6
    //            /  \
    //           9    1
    //          / \    \
    //          3  4    13
    // */

    // Node *root2 = new Node(4);
    // root2->left = new Node(9);
    // root2->right = new Node(1);
    // root2->left->left = new Node(3);
    // root2->left->right = new Node(6);
    // root2->right->right = new Node(13);

    // inorder(root2);
    // cout << "\n";

    // restoreBST(root2);

    // inorder(root2);
    // cout << "\n";
    return 0;
}