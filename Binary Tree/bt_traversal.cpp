 #include <bits/stdc++.h>
using namespace std;
// pre order traversal
// root -> left -> right

// in order traversal
// left -> root -> right

// postorder traversal
// left ->right -> root

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

void preoder(struct node *node)
{
  if (node == NULL)
    return;

  cout << node->data << " " ;
  preoder(node->left);
  preoder(node->right);
}

void inorder(struct node *node)
{
  if (node == NULL)
    return;

  inorder(node->left);
  cout << node->data << " ";
  inorder(node->right);
}

void postorder(struct node *node)
{
  if (node == NULL)
    return;

  postorder(node->left);
  postorder(node->right);
  cout << node->data << " ";
}
int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);

  /*
       1
     /   \
    2    3

  */

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);

  root->right->right->left = new node(8);
  root->right->right->right = new node(9);

  root->right->left->right = new node(10);
  root->right->left->left = new node(11);


  /*
       1
     /   \
    2     3
  /   \  / \
  4   5  6  7
  */
//  inorder(root);
//  cout<<endl;
//  preoder(root);
//  cout<<endl;
 postorder(root);
//  cout<<endl;
 return 0;
}