#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

// AVL Tree
// AVL tree is a self balancing binary search tree
// in AVL tree the difference between the height of left subtree and right subtree is atmost 1
// if the difference is more than 1 then we need to balance the tree
// there are 4 cases for balancing the tree
// 1. LL rotation
// 2. RR rotation
// 3. LR rotation
// 4. RL rotation

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// height of the tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

// balance factor of the tree
int balanceFactor(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// right rotation
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // updating height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // returning new root
    return x;
}

// left rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // updating height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // returning new root
    return y;
}

// inserting a node in the tree
Node *insert(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        return new Node(d);
    }

    // recursive case
    if (d <= root->data)
    {
        root->left = insert(root->left, d);
    }
    else
    {
        root->right = insert(root->right, d);
    }

    // updating height
    root->height = max(height(root->left), height(root->right)) + 1;

    // checking balance factor
    int bf = balanceFactor(root);

    // LL rotation
    if (bf > 1 && d < root->left->data)
    {
        return rightRotate(root);
    }

    // RR rotation
    if (bf < -1 && d > root->right->data)
    {
        return leftRotate(root);
    }

    // LR rotation
    if (bf > 1 && d > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL rotation
    if (bf < -1 && d < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// printing the tree
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

void printSpace(double n, Node *removed)
{
    for (; n > 0; n--)
    {
        cout << "   ";
    }
    if (removed == NULL)
    {
        cout << " ";
    }
    else
    {
        cout << removed->data;
    }
}

void printBinary(Node *root)
{
    list<Node *> treeLevel;
    treeLevel.push_back(root);
    list<Node *> temp;
    int counter = 0;
    int ht = height(root) - 1;
    double numberOfElements = pow(2, (ht + 1)) - 1;
    while (counter <= ht)
    {
        Node *removed = treeLevel.front();
        treeLevel.pop_front();
        if (temp.empty())
        {
            printSpace(numberOfElements / pow(2, counter + 1), removed);
        }
        else
        {
            printSpace(numberOfElements / pow(2, counter), removed);
        }
        if (removed == NULL)
        {
            temp.push_back(NULL);
            temp.push_back(NULL);
        }
        else
        {
            temp.push_back(removed->left);
            temp.push_back(removed->right);
        }

        if (treeLevel.empty())
        {
            cout << endl
                 << endl;
            treeLevel = temp;
            temp.clear();
            counter++;
        }
    }
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        int d;
        cout << "> ";
        cin >> d;
        root = insert(root, d);
        printBinary(root);
        cout << endl;
    }

    return 0;
}