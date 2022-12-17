#include <iostream>
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

#define n 100
class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty " << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    node *head = NULL;
    stack st;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);

    
    for (int i = 0; i <= length(head) + 4; i++)
    {
        // cout << head->data<<" ";
        st.push(head->data);
        head = head->next;
    }
    
    for (int i = 0; i < 6; i++)
    {

       cout << st.Top()<<" ";
        st.pop();
    }

    return 0;
}
