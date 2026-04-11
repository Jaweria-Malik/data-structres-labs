#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    string name;
    float marks;
    Node* next;
};

Node* head = NULL;

void insert(int roll, string name, float marks) {
    Node* newNode = new Node();
    newNode->roll = roll;
    newNode->name = name;
    newNode->marks = marks;
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

void deleteStudent(int roll) {
    if (head == NULL) {
        cout << "List Empty\n";
        return;
    }

    if (head->roll == roll) {
        head = head->next;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->roll != roll)
        temp = temp->next;

    if (temp->next == NULL)
        cout << "Not Found\n";
    else
        temp->next = temp->next->next;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->roll << " " << temp->name << " " << temp->marks << endl;
        temp = temp->next;
    }
}

void search(int roll) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << temp->name << " " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

void update(int roll) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Enter new name & marks: ";
            cin >> temp->name >> temp->marks;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

void stats() {
    Node* temp = head;
    float sum = 0, max = -1, min = 101;
    int count = 0;

    while (temp != NULL) {
        sum += temp->marks;
        if (temp->marks > max) max = temp->marks;
        if (temp->marks < min) min = temp->marks;
        count++;
        temp = temp->next;
    }

    if (count == 0) {
        cout << "No Data\n";
        return;
    }

    cout << "Average: " << sum / count << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

int main() {
    int choice, roll;
    string name;
    float marks;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Update\n6.Stats\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> roll >> name >> marks;
            insert(roll, name, marks);
            break;
        case 2:
            cin >> roll;
            deleteStudent(roll);
            break;
        case 3:
            display();
            break;
        case 4:
            cin >> roll;
            search(roll);
            break;
        case 5:
            cin >> roll;
            update(roll);
            break;
        case 6:
            stats();
            break;
        }
    } while (choice != 0);
}
