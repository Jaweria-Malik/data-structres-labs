#include <iostream>
#include <queue>
using namespace std;

class TicketSystem {
private:
    queue<int> tickets;

public:
    void enqueue(int ticket_id) {
        tickets.push(ticket_id);
        cout << "Ticket " << ticket_id << " added.\n";
    }

    void dequeue() {
        if (tickets.empty()) {
            cout << "No tickets to resolve.\n";
        }
        else {
            cout << "Resolved Ticket: " << tickets.front() << endl;
            tickets.pop();
        }
    }

    void front() {
        if (tickets.empty()) {
            cout << "No pending tickets.\n";
        }
        else {
            cout << "Next Ticket: " << tickets.front() << endl;
        }
    }

    void display() {
        if (tickets.empty()) {
            cout << "No pending tickets.\n";
            return;
        }
        cout << "Pending Tickets: ";
        queue<int> temp = tickets;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    TicketSystem ts;
    int choice, ticket_id;

    do {
        cout << "\n--- Customer Support Ticket System ---\n";
        cout << "1. Add Ticket\n2. Resolve Ticket\n3. Next Ticket\n4. Display Pending Tickets\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            ts.enqueue(ticket_id);
            break;
        case 2:
            ts.dequeue();
            break;
        case 3:
            ts.front();
            break;
        case 4:
            ts.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
