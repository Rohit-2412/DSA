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
node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummyNode = new node(-1);
    node *p3 = dummyNode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}

node *mergeRecursive(node *head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head1;
    }
    if (head2 == NULL)
    {
        return head2;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    vector<int> v1 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    for (int i = 0; i < v1.size(); i++)
    {
        insertAtTail(head1, v1[i]);
    }
    display(head1);

    vector<int> v2 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    for (int i = 0; i < v2.size(); i++)
    {
        insertAtTail(head2, v2[i]);
    }
    display(head2);

    node *newhead = merge(head1, head2);
    display(newhead);

    // node *newhead = mergeRecursive(head1, head2);
    // display(newhead);
    return 0;
}