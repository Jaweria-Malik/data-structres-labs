#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node* insertBegin(Node* head, int value)
{
    if (head == NULL) return new Node(value);

    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

Node* insertEnd(Node* head, int value)
{
    if (head == NULL) return new Node(value);

    head->next = insertEnd(head->next, value);
    return head;
}

Node* insertPos(Node* head, int value, int pos)
{
    if (pos == 1)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    head->next = insertPos(head->next, value, pos - 1);
    return head;
}

Node* deleteValue(Node* head, int value)
{
    if (head == NULL) return NULL;

    if (head->data == value)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deleteValue(head->next, value);
    return head;
}

Node* deletePos(Node* head, int pos)
{
    if (head == NULL) return NULL;

    if (pos == 1)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deletePos(head->next, pos - 1);
    return head;
}

int search(Node* head, int value, int pos)
{
    if (head == NULL) return -1;

    if (head->data == value) return pos;

    return search(head->next, value, pos + 1);
}

void print(Node* head)
{
    if (head == NULL) return;

    cout << head->data << " ";
    print(head->next);
}

int main()
{
    Node* head = NULL;

    head = insertBegin(head, 10);
    head = insertEnd(head, 20);
    head = insertPos(head, 15, 2);

    print(head);

    cout << endl << search(head, 20, 1) << endl;

    head = deleteValue(head, 10);
    print(head);

    return 0;
}