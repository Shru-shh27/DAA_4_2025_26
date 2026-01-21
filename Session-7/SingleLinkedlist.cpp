#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int d) {
        val = d;
        next = NULL;
    }
};

void insert(node*& head, int data) {
    node* newnode = new node(data);

    if (head == NULL) {
        head = newnode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deletenode(node*& head, int data) {
    if (head == NULL) return;

    if (head->val == data) {
        node* del = head;
        head = head->next;
        delete del;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->val == data) {
            node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}

void middlell(node* head) {
    if (head == NULL) return;

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->val << endl;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    print(head);
    middlell(head);

    return 0;
}
