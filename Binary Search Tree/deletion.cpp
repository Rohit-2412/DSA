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

Node *insertBST(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        // when val > root->data
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // case 3 when key has both left and right nodes

        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    vector<int> v;
    v = {4, 2, 5, 1, 3, 6};
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            root = insertBST(root, v[i]);
            continue;
        }
        insertBST(root, v[i]);
    }

    inorder(root);
    cout << "\n";
    root = deleteInBST(root, 2);
    inorder(root);

    return 0;
}