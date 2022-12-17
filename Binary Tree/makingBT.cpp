#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

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

Node *newNode(int data)
{
    Node *node = new Node(data);
    node->data = (data);
    node->left = node->right = NULL;
    return node;
}

Node *insertLevelOrder(vi arr, Node *root, int i, int n)
{
    if (i < n)
    {
        Node *temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

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
    // int n;
    // cin >> n;
    vi v;
    v = {1, 2, 3, 4, 5, 6, 7};

    Node *root = insertLevelOrder(v, root, 0, v.size());

    preorder(root);

    return 0;
}