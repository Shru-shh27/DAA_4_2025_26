#include <iostream>
using namespace std;

struct node
{
    int val;
    node *prev;
    node *next;

    node(int d)
    {
        val = d;
        prev = NULL;
        next = NULL;
    }
};

void insertAtPos(node *&head, int data, int pos)
{
    node *newnode = new node(data);

    if (pos == 1)
    {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

void deleteAtPos(node *&head, int pos)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        node *del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete del;
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void middleElement(node *head)
{
    if (head == NULL)
        return;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->val << endl;
}

void printLL(node *head)
{

    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    insertAtPos(head, 10, 1);
    insertAtPos(head, 20, 2);
    insertAtPos(head, 30, 3);
    insertAtPos(head, 40, 4);
    insertAtPos(head, 25, 3);

    printLL(head);

    middleElement(head);

    deleteAtPos(head, 3);
    printLL(head);

    middleElement(head);

    return 0;
}
