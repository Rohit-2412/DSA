#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N = 1e5 + 7, MOD = 1e9 + 7;

// Representation of a node
struct Node
{
    int data;
    Node *next;
};

// Function to insert node
void insert(Node **root, int item)
{
    Node *temp = new Node;
    Node *ptr;
    temp->data = item;
    temp->next = NULL;

    if (*root == NULL)
        *root = temp;
    else
    {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

Node *arrayToList(vi arr, int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
    return root;
}

void display(Node *root)
{
    while (root != NULL)
    {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main()
{
    // int arr[] = {1, 2, 3, 4, 5};
    vi arr = {1, 2, 3, 4, 1, 2, 3, 4, 5, 5, 6, 7, 8, 5};
    int n = arr.size();
    Node *root = arrayToList(arr, n);
    display(root);
    return 0;
}
