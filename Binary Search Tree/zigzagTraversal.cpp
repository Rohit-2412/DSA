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

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            // Left to Right Case
            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }

                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            // Right to Left case
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }

                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currLevel.empty())
        {
            leftToRight = !leftToRight;

            swap(currLevel, nextLevel);
        }
    }
}

// reverse zigzagTraversal

void revZigZagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = false;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            // Right to Left Case
            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }

                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            // Left To Right Case
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }

                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currLevel.empty())
        {
            leftToRight = !leftToRight;

            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    /*
          12
        9   15
      5  10
    */

    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    // testing
    zigzagTraversal(root);
    cout << endl;
    revZigZagTraversal(root);
    cout << endl;

    return 0;
}