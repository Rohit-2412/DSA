#include <bits/stdc++.h>
using namespace std;
/*


*/
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
node *reverseK(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reverseK(nextptr, k);
    }
    return prevptr;
}

int main()
{
    node* head=NULL;
    insertAtHead(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    // insertAtTail(head,7);
    display(head);
    int k=2;
    node* newhead=reverseK(head,k);
    display(newhead);

    return 0;
}
