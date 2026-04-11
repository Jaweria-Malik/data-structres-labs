#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteByValue(int value) {
        if (head == NULL) return;

        if (head->data == value) {
            head = head->next;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value)
            temp = temp->next;

        if (temp->next != NULL)
            temp->next = temp->next->next;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(5);
    list.insertAtEnd(10);
    list.insertAtEnd(20);

    list.display();

    list.deleteByValue(10);
    list.display();
}
