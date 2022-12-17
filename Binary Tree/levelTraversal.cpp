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

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}

int sumAtK(Node *root, int K)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int sum = 0;
    int level = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == K)
            {
                sum += node->data;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main()
{
    Node *root = new Node(1); // lvl 0
    root->left = new Node(2); // lvl 1
    root->right = new Node(3);
    root->left->left = new Node(4); // lvl 2
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->left->right = new Node(7);
    root->left->left->left = new Node(8); // lvl 3
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    // find the sum of nodes at kth level
    // printLevelOrder(root);
    cout << sumAtK(root, 1) << endl;
    cout << sumAtK(root, 2) << endl;
    cout << sumAtK(root, 3) << endl;
    return 0;
}