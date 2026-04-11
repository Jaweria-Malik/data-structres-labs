#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at position
void insertAtPosition(int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL) return;

    if (pos == 1) {
        head = head->next;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    temp->next = temp->next->next;
}

// Search
void search(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not Found\n";
}

// Count
void countNodes() {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total Nodes: " << count << endl;
}

// Display
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, pos;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Count\n5.Display\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value & Position: ";
            cin >> value >> pos;
            insertAtPosition(value, pos);
            break;

        case 2:
            cout << "Position: ";
            cin >> pos;
            deleteAtPosition(pos);
            break;

        case 3:
            cout << "Value: ";
            cin >> value;
            search(value);
            break;

        case 4:
            countNodes();
            break;

        case 5:
            display();
            break;
        }
    } while (choice != 0);
}
