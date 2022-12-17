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

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return -1;

    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc]) // checking common nodes
        {
            break;
        }
    }
    return path1[pc - 1]; // counter is at next position of lca so decrement by one for answer
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

    int n1 = 4;
    int n2 = 6;
    int lca = LCA(root, n1, n2);
    if (lca == -1)
    {
        cout << "LCA Doesn't exist." << endl;
    }
    else
        cout << "LCA : " << lca << endl;

    return 0;
}
/*
using recursion :
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
if (root.val < p.val && root.val < q.val) {
            return lowestCommonAncestor(root.right, p, q);
        }

        else if (root.val > p.val && root.val > q.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        else {
            return root;
        }
}
*/