#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search1(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *buildTree1(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    node *Node = new node(curr);
    int pos = search1(inorder, start, end, curr);
    Node->left = buildTree1(preorder, inorder, start, pos - 1);
    Node->right = buildTree1(preorder, inorder, pos + 1, end);
    return Node;
}

// build tree postorder from inorder

int search2(int inorder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        return i;
    }
    return -1;
}

node *buildTree2(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }

    int val = postorder[idx];
    idx--;
    node *curr = new node(val);
    if (start == end)
    {
        return curr;
    }
    int pos = search2(inorder, start, end, val);

    curr->right = buildTree2(postorder, inorder, pos + 1, end);
    curr->left = buildTree2(postorder, inorder, start, pos - 1);
    return curr;
}

void inorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void postorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    int postorder[] = {4, 2, 5, 3, 1};

    // build tree
    // node *root1 = buildTree1(preorder, inorder, 0, 4);
    node *root2 = buildTree2(postorder, inorder, 0, 4);
    // inorderPrint(root1);

    postorderPrint(root2);

    return 0;
}