#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node* insertBegin(Node* head, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL) return newNode;

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node* insertEnd(Node* head, int value)
{
    if (head == NULL) return new Node(value);

    head->next = insertEnd(head->next, value);
    head->next->prev = head;

    return head;
}

Node* insertPos(Node* head, int value, int pos)
{
    if (pos == 1)
    {
        Node* newNode = new Node(value);

        if (head != NULL)
        {
            newNode->next = head;
            head->prev = newNode;
        }

        return newNode;
    }

    head->next = insertPos(head->next, value, pos - 1);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

Node* deleteValue(Node* head, int value)
{
    if (head == NULL) return NULL;

    if (head->data == value)
    {
        Node* temp = head->next;

        if (temp != NULL)
            temp->prev = NULL;

        delete head;
        return temp;
    }

    head->next = deleteValue(head->next, value);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

Node* deletePos(Node* head, int pos)
{
    if (head == NULL) return NULL;

    if (pos == 1)
    {
        Node* temp = head->next;

        if (temp != NULL)
            temp->prev = NULL;

        delete head;
        return temp;
    }

    head->next = deletePos(head->next, pos - 1);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

int search(Node* head, int value, int pos)
{
    if (head == NULL) return -1;

    if (head->data == value) return pos;

    return search(head->next, value, pos + 1);
}

void printForward(Node* head)
{
    if (head == NULL) return;

    cout << head->data << " ";
    printForward(head->next);
}

void printReverse(Node* head)
{
    if (head == NULL) return;

    printReverse(head->next);
    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;

    head = insertBegin(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertPos(head, 5, 2);

    printForward(head);
    cout << endl;

    printReverse(head);
    cout << endl;

    cout << search(head, 3, 1);

    return 0;
}