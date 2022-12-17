#include <bits/stdc++.h>
using namespace std;
// declaring linked list
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
// inserting element at head
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
// inserting element at tail
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
// display a linked lsit
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

// for length of linked list
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

int intersection(node *&head, node *&head2)
{
    int l1 = length(head);
    int l2 = length(head2);

    int d = 0;
    node *ptr1; // iterator for longer linked list
    node *ptr2; // iterator for shorter linked list
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head;
        ptr2 = head2;
    }
    if (l1 <= l2)
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head;
    }
    while (d != 0)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL & ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
int main()
{
    node *head = NULL;
    node *head2 = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    display(head);

    insertAtHead(head2, 9);
    insertAtTail(head2, 0);
    insertAtTail(head2, 6);
    insertAtTail(head2, 7);

    display(head2);

    // for intersecting LL
    head->next->next->next->next->next->next = head2->next->next;

    cout << intersection(head, head2) << endl;

    return 0;
}
