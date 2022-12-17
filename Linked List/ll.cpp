#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// search
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// if we want to delete first node of LL
void delteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
// reverse a linked list
// iterative way
node *reverse(node *&head)
{

    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

// recursuve way
node *reverseRecursive(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
int main()
{
    node *head = NULL;
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);
    // node* newhead = reverse(head);
    // node* newhead = reverseRecursive(head);
    // display(newhead);
    // cout<<search(head,5)<<endl;
    // deletion(head, 5);
    // display(head);
    // delteAtHead(head);
    // display(head);
    // cout<<search(head,5)<<endl;
    return 0;
}