#include <iostream>
#include <queue>
#include <string>
using namespace std;

class PrintQueue {
private:
    queue<string> documents;

public:
    void enqueue(string docName) {
        documents.push(docName);
        cout << "Added document: " << docName << endl;
    }

    void dequeue() {
        if (documents.empty()) {
            cout << "No documents to print.\n";
        }
        else {
            cout << "Printing document: " << documents.front() << endl;
            documents.pop();
        }
    }

    void front() {
        if (documents.empty()) {
            cout << "No documents in queue.\n";
        }
        else {
            cout << "Next document to print: " << documents.front() << endl;
        }
    }

    void display() {
        if (documents.empty()) {
            cout << "No pending documents.\n";
            return;
        }
        cout << "Pending Documents: ";
        queue<string> temp = documents;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PrintQueue pq;
    int choice;
    string docName;

    do {
        
        cout << "1. Add Document\n2. Print Document\n3. Next Document\n4. Display Pending Documents\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin >> ws; 
            getline(cin, docName);
            pq.enqueue(docName);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.front();
            break;
        case 4:
            pq.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
