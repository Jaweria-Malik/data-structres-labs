#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
};

Node* head = NULL;

void addPatient(string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void removePatient(string name) {
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

void displayPatients() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void countPatients() {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total Patients: " << count << endl;
}

int main() {
    addPatient("Ali");
    addPatient("Sara");
    addPatient("Ahmed");

    displayPatients();

    removePatient("Sara");
    displayPatients();

    countPatients();
}
