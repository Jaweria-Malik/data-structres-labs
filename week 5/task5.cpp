#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int priority;
    Node* next;
};

// Insert with priority (higher first)
void addStudent(Node*& head, string name, int priority) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || priority > head->priority) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->priority >= priority)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void removeStudent(Node*& head, string name) {
    if (head == NULL) return;

    if (head->name == name) {
        head = head->next;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->name != name)
        temp = temp->next;

    if (temp->next != NULL)
        temp->next = temp->next->next;
}

void serveStudent(Node*& head) {
    if (head != NULL)
        head = head->next;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->name << "(" << head->priority << ") -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* book1 = NULL;
    Node* book2 = NULL;

    addStudent(book1, "Ali", 2);
    addStudent(book1, "Sara", 5);
    addStudent(book1, "Ahmed", 3);

    addStudent(book2, "Zara", 4);
    addStudent(book2, "Usman", 1);

    cout << "Book 1 Queue:\n";
    display(book1);

    cout << "Book 2 Queue:\n";
    display(book2);

    serveStudent(book1);
    cout << "After Serving Book 1:\n";
    display(book1);
}
